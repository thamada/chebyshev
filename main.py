import pdfkit
import os

# HTMLコンテンツの作成
html_content = '''
<!DOCTYPE html>
<html lang="ja">
<head>
    <meta charset="UTF-8">
    <title>チェビシェフ多項式補間</title>
    <!-- MathJaxの読み込み -->
    <script src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>
    <style>
        body {
            font-family: "Noto Sans JP", sans-serif;
            margin: 40px;
            line-height: 1.6;
        }
        h1 {
            font-size: 24px;
            margin-bottom: 16px;
        }
        h2 {
            font-size: 20px;
            margin-top: 24px;
            margin-bottom: 12px;
        }
        p {
            margin-bottom: 12px;
        }
        ul, ol {
            margin-bottom: 12px;
            padding-left: 20px;
        }
        li {
            margin-bottom: 6px;
        }
    </style>
</head>
<body>

<h1>チェビシェフ多項式補間</h1>

<h2>1. 多項式補間の概要</h2>

<p>多項式補間は、与えられた有限のデータ点を通る多項式を求め、その多項式を用いて未知の点での関数値を推定する手法です。しかし、等間隔のノード（データ点）を用いて高次の多項式補間を行うと、<strong>ランゲ現象</strong>と呼ばれる現象が発生し、補間誤差が大きくなることがあります。</p>

<h2>2. ランゲ現象</h2>

<p>ランゲ現象は、特に補間区間の端点付近で補間多項式が大きく振動し、補間誤差が増大する問題です。これは、高次の多項式がデータ点間で急激に変化するために起こります。</p>

<h2>3. チェビシェフ多項式の紹介</h2>

<p>チェビシェフ多項式は、数値解析や近似理論で重要な役割を果たす直交多項式です。第一種チェビシェフ多項式 \\( T_n(x) \\) は、以下のように定義されます：</p>

<p>\\[
T_n(x) = \\cos(n \\arccos x), \\quad -1 \\leq x \\leq 1
\\]</p>

<p>ここで、\\( n \\) は多項式の次数です。</p>

<h2>4. チェビシェフノードの定義</h2>

<p>チェビシェフ多項式補間では、特別に選ばれたノード（データ点）を用います。これらのノードは<strong>チェビシェフノード</strong>と呼ばれ、以下の式で定義されます：</p>

<p>\\[
x_i = \\cos\\left( \\frac{2i - 1}{2n} \\pi \\right), \\quad i = 1, 2, \\dots, n
\\]</p>

<p>これらのノードは、区間 \\([-1, 1]\\) で端点に近づくほど密になります。</p>

<h2>5. チェビシェフ多項式補間の手順</h2>

<ol>
    <li><strong>関数値の計算</strong>：与えられた関数 \\( f(x) \\) の値を、チェビシェフノード \\( x_i \\) で評価します。</li>
    <li><strong>補間多項式の構築</strong>：得られたデータ点 \\( (x_i, f(x_i)) \\) を用いて、チェビシェフ多項式を基底とする補間多項式 \\( P_{n-1}(x) \\) を構築します。
        <p>補間多項式は次のように表されます：</p>
        <p>\\[
        P_{n-1}(x) = \\sum_{k=0}^{n-1} a_k T_k(x)
        \\]</p>
        <p>ここで、\\( a_k \\) はチェビシェフ係数で、以下の式で計算されます：</p>
        <p>\\[
        a_k = \\frac{2}{n} \\sum_{i=1}^{n} f(x_i) T_k(x_i), \\quad k = 0, 1, \\dots, n-1
        \\]</p>
        <p>\\( k = 0 \\) の場合、係数は \\( \\frac{1}{n} \\) となります。</p>
    </li>
</ol>

<h2>6. チェビシェフ多項式補間の利点</h2>

<ul>
    <li><strong>ランゲ現象の軽減</strong>：チェビシェフノードを用いることで、補間多項式の振動を抑え、ランゲ現象を軽減できます。</li>
    <li><strong>誤差の最小化</strong>：チェビシェフ多項式補間は、最大誤差を最小限に抑える「最良一致近似」に近い特性を持ちます。</li>
    <li><strong>数値安定性の向上</strong>：チェビシェフ多項式は直交性を持つため、計算時の数値的不安定性を減少させます。</li>
</ul>

<h2>7. 具体例</h2>

<p>例えば、関数 \\( f(x) = \\frac{1}{1 + 25x^2} \\) を補間したいとします。等間隔のノードを用いるとランゲ現象が発生しやすいですが、チェビシェフノードを用いることで滑らかな補間結果が得られます。</p>

<h2>8. まとめ</h2>

<p>チェビシェフ多項式補間は、高次の多項式補間における問題点を克服するための有効な手法です。特別に選ばれたチェビシェフノードを用いることで、補間多項式の振動を抑え、より正確な近似を実現します。数値解析、信号処理、データフィッティングなど、さまざまな分野で広く活用されています。</p>

</body>
</html>
'''

# HTMLファイルとして保存
html_file = 'work/chebyshev_interpolation.html'
with open(html_file, 'w', encoding='utf-8') as f:
    f.write(html_content)

# PDFオプションの設定
options = {
    'page-size': 'A4',
    'encoding': 'UTF-8',
    'margin-top': '20mm',
    'margin-bottom': '20mm',
    'margin-left': '20mm',
    'margin-right': '20mm',
    'enable-local-file-access': None,
}

# wkhtmltopdfのパスを指定する場合（必要に応じてパスを設定）
# config = pdfkit.configuration(wkhtmltopdf='/usr/local/bin/wkhtmltopdf')

# PDFの生成
pdf_file = 'work/chebyshev_interpolation.pdf'
pdfkit.from_file(html_file, pdf_file, options=options)

# 生成したHTMLファイルを削除（必要に応じて）
# os.remove(html_file)

print(f"{pdf_file} が生成されました。")

