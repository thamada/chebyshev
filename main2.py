from reportlab.pdfgen import canvas
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.cidfonts import UnicodeCIDFont
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.pdfbase import ttfonts, pdfmetrics
from reportlab.pdfbase.pdfmetrics import registerFont
from reportlab.lib.fonts import addMapping


def create_pdf(filename):
    c = canvas.Canvas(filename)

    # 日本語フォントの登録
    pdfmetrics.registerFont(UnicodeCIDFont('HeiseiKakuGo-W5'))
    c.setFont('HeiseiKakuGo-W5', 16)

    # タイトル
    c.drawString(100, 750, "チェビシェフ多項式補間")

    c.setFont("HeiseiKakuGo-W5", 9)
    c.drawString(100, 720, "1. 多項式補間の概要")
    c.drawString(100, 700, "チェビシェフ多項式補間は、最大誤差を最小限に抑える「最良一致近似」に近い特性を持ちます。")
    c.drawString(100, 670, "また、チェビシェフ多項式は直交性を持つため、計算時の数値的不安定性を減少させます。")
    items = ["りんご", "バナナ", "いちご", "メロン", "オレンジ", "スイカ"]
    for i, item in enumerate(items):
        c.drawString(120, 650 - i * 20, f"- {item}")

    c.drawString(100, 530, "注意事項:")
    c.drawString(120, 510, "食べ過ぎに注意すること")

    c.drawString(100, 460, "以上")

    c.save()

# PDFファイルの生成
create_pdf("work/result.pdf")

