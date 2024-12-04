#include <stdio.h>
#include <math.h>

#define N 3  // チェビシェフ多項式の次数

// チェビシェフ多項式Tn(x)の計算
double chebyshev_polynomial(int n, double x) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else {
        return 2 * x * chebyshev_polynomial(n - 1, x) - chebyshev_polynomial(n - 2, x);
    }
}

// 補間関数log(1+x)の定義
double f(double x) {
  //return log(1 + x);
    return x*(x-0.25)*(x-0.5)*(x-1.0);
}

int main() {
    double a = 0.0, b = 1.0;  // 区間[0, 1]
    double nodes[N + 1];      // 等間隔ノード
    double coeffs[N + 1];     // チェビシェフ多項式の係数

    // 等間隔ノードの計算
    for (int i = 0; i <= N; i++) {
        nodes[i] = a + (b - a) * i / N;
    }

    // 係数の計算
    for (int i = 0; i <= N; i++) {
        coeffs[i] = 0;
        for (int j = 0; j <= N; j++) {
            coeffs[i] += f(nodes[j]) * chebyshev_polynomial(i, nodes[j]);
        }
        coeffs[i] /= (N + 1);
    }

    // 補間の結果を表示
    printf("チェビシェフ多項式による補間結果:\n");
    for (double x = a; x <= b; x += 1.0/1024.0) {
        double interpolation = 0;
        for (int i = 0; i <= N; i++) {
            interpolation += coeffs[i] * chebyshev_polynomial(i, x);
        }
        //printf("x = %lf, log(1+x) = %lf, 補間値 = %lf\n", x, f(x), interpolation);
        double diff = fabs(f(x) - interpolation);
        double err = fabs(diff/f(x));
        
        printf("%f\t%f\t%f\t%e\t%e\n", x, f(x), interpolation, diff, err);
    }

    return 0;
}

