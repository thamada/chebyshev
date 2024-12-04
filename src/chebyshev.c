#include <stdio.h>
#include <math.h>

#define N 1  // チェビシェフ多項式の次数

// チェビシェフ多項式の計算関数
/**
void chebyshev_coefficients(double (*f)(double), double a, double b, int n, double* coeff) {
    for (int k = 0; k <= n; k++) {
        double sum = 0.0;
        for (int i = 0; i <= n+1; i++) {
            double x_i = cos(M_PI * (2 * i + 1) / (2.0 * (n + 1)));
            double x_mapped = 0.5 * (b - a) * (x_i + 1) + a;
            sum += f(x_mapped) * cos(k * M_PI * (2 * i + 1) / (2.0 * (n + 1)));
        }
        coeff[k] = (2.0 / (n + 1)) * sum;
    }
    coeff[0] *= 0.5;  // 最初の係数は半分にする
}
*/

void chebyshev_coefficients(double (*f)(double), double a, double b, int n, double* coeff) {
    for (int k = 0; k <= n; k++) {
        double sum = 0.0;
        int ni = 1024;
        for (int i = 0; i < ni; i++) {
          double x_i = cos(M_PI * (2 * i + 1) / (2.0 * ni));
          double x_mapped = 0.5 * (b - a) * (x_i + 1) + a;
          sum += f(x_mapped) * cos(k * M_PI * (2 * i + 1) / (2.0 * ni));
        }
        coeff[k] = (2.0 / (ni + 1)) * sum;
    }
    coeff[0] *= 0.5;  // 最初の係数は半分にする
}



// チェビシェフ補間の評価関数
double chebyshev_interpolate(double x, double a, double b, int n, double* coeff) {
    double y = 2.0 * (x - a) / (b - a) - 1.0;
    double T_prev = 1;
    double T_curr = y;
    double result = coeff[0] + coeff[1] * y;

    for (int k = 2; k <= n; k++) {
        double T_next = 2 * y * T_curr - T_prev;
        result += coeff[k] * T_next;
        T_prev = T_curr;
        T_curr = T_next;
    }
    return result;
}

// 対象の関数
double func(double x) {
  //   return log(1 + x);
  //  return x*(x-0.25)*(x-0.5)*(x-1.0);
  return x*(x-0.5)*(x-1.0);
}

int main() {
    double a = 0.0;
    double b = 1.0;
    double coeff[N + 1];

    // チェビシェフ係数を計算
    chebyshev_coefficients(func, a, b, N, coeff);

    // 結果を表示
    fprintf(stderr, "チェビシェフ補間の係数:\n");
    for (int i = 0; i <= N; i++) {
        fprintf(stderr, "c[%d] = %f\n", i, coeff[i]);
    }


    // 任意の点で補間値を計算
    for (double x = a; x <= b; x += 1.0/1024.0) {
      double z_cheby = chebyshev_interpolate(x, a, b, N, coeff);
      double z_truth = func(x);

      double diff = fabs(z_truth - z_cheby);
      double err = fabs(diff / z_truth);

      printf("%f\t%f\t%f\t%e\t%e\n", x, z_truth, z_cheby, diff, err);

    }

    return 0;
} 
