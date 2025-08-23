#include "cec14_test_func.h"
#include <cstdio>
#include <cstring>

Cec14TestFunc::Cec14TestFunc(int nx, int func_id)
    : nx_(nx), func_id_(func_id)
{
    load_all_files();   // 讀 OShift_/M_/SS_（用 "%lf" 對 double）
    alloc_buffers();    // y_/z_/x_bound_.resize(nx_)
}

Cec14TestFunc::~Cec14TestFunc() {
    // 這是 Destructor（解構子），在你 delete 這個物件時會自動被呼叫，用來：
	// 1. 釋放建構子中配置的資源
    // 2. 如果你用 std::vector、std::unique_ptr 等安全容器，它就什麼都不用寫，自然釋放
}

void Cec14TestFunc::Evaluate(double* x, double* f, int mx) const {
    // 若先支援 mx=1：直接派發
    for (int i = 0; i < mx; i++)
    {
		switch (func_id_)
		{
		case 1:
			ellips_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 100.0;
			break;
		case 2:
			bent_cigar_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 200.0;
			break;
		case 3:
			discus_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 300.0;
			break;
		case 4:
			rosenbrock_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 400.0;
			break;
		case 5:
			ackley_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 500.0;
			break;
		case 6:
			weierstrass_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 600.0;
			break;
		case 7:
			griewank_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 700.0;
			break;
		case 8:
			rastrigin_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 0);
			//f[i] += 800.0;
			break;
		case 9:
			rastrigin_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 900.0;
			break;
		case 10:
			schwefel_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 0);
			//f[i] += 1000.0;
			break;
		case 11:
			schwefel_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 1100.0;
			break;
		case 12:
			katsuura_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 1200.0;
			break;
		case 13:
			happycat_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 1300.0;
			break;
		case 14:
			hgbat_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 1400.0;
			break;
		case 15:
			grie_rosen_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 1500.0;
			break;
		case 16:
			escaffer6_func(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1, 1);
			//f[i] += 1600.0;
			break;
		case 17:
			hf01(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1, 1);
			//f[i] += 1700.0;
			break;
		case 18:
			hf02(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1, 1);
			//f[i] += 1800.0;
			break;
		case 19:
			hf03(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1, 1);
			//f[i] += 1900.0;
			break;
		case 20:
			hf04(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1, 1);
			//f[i] += 2000.0;
			break;
		case 21:
			hf05(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1, 1);
			//f[i] += 2100.0;
			break;
		case 22:
			hf06(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1, 1);
			//f[i] += 2200.0;
			break;
		case 23:
			cf01(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1);
			//f[i] += 2300.0;
			break;
		case 24:
			cf02(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1);
			//f[i] += 2400.0;
			break;
		case 25:
			cf03(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1);
			//f[i] += 2500.0;
			break;
		case 26:
			cf04(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1);
			//f[i] += 2600.0;
			break;
		case 27:
			cf05(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1);
			//f[i] += 2700.0;
			break;
		case 28:
			cf06(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), 1);
			//f[i] += 2800.0;
			break;
		case 29:
			cf07(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1);
			//f[i] += 2900.0;
			break;
		case 30:
			cf08(&x[i * nx_], &f[i], nx_, OShift_.data(), M_.data(), SS_.data(), 1);
			//f[i] += 3000.0;
			break;
		default:
			printf("\nError: There are only 30 test functions in this test suite!\n");
			f[i] = 0.0;
			break;
		}
    }
}

void Cec14TestFunc::GetBounds(double& lower_bound, double& upper_bound) const {
	// 根據 func_id_ 返回對應的邊界
	// CEC14 所有函數的邊界都是 -100.0 到 100.0
	lower_bound = -100.0;
	upper_bound = 100.0;
}

void Cec14TestFunc::load_all_files() {
	// 依 func_id_ 決定要讀的檔（shift_data/M/shuffle）
	// 用 fopen/fscanf("%lf", ...) 讀到 OShift_/M_（避免之前的 %Lf 錯誤）
	// OShift_.resize(...); M_.resize(...); SS_.resize(...);
	FILE* fpt;
	char FileName[256];

	// 檢查維度合法性
	if (!(nx_ == 2 || nx_ == 10 || nx_ == 20 || nx_ == 30 || nx_ == 50 || nx_ == 100)) {
		printf("\nError: Test functions are only defined for D=2,10,20,30,50,100.\n");
		return;
	}
	if (nx_ == 2 && ((func_id_ >= 17 && func_id_ <= 22) || (func_id_ >= 29 && func_id_ <= 30))) {
		printf("\nError: hf01~hf06, cf07, cf08 are NOT defined for D=2.\n");
		return;
	}

	// === 讀取 M 矩陣 ===
	sprintf(FileName, "input_data/M_%d_D%d.txt", func_id_, nx_);
	fpt = fopen(FileName, "r");
	if (fpt == NULL) {
		printf("\n Error: Cannot open input file %s \n", FileName);
		return;
	}
	if (func_id_ < 23) {
		M_.resize(nx_ * nx_);
		for (int i = 0; i < nx_ * nx_; i++) {
			fscanf(fpt, "%lf", &M_[i]);
		}
	}
	else {
		M_.resize(cf_num_ * nx_ * nx_);
		for (int i = 0; i < cf_num_ * nx_ * nx_; i++) {
			fscanf(fpt, "%lf", &M_[i]);
		}
	}
	fclose(fpt);

	// === 讀取 shift_data ===
	sprintf(FileName, "input_data/shift_data_%d.txt", func_id_);
	fpt = fopen(FileName, "r");
	if (fpt == NULL) {
		printf("\n Error: Cannot open input file %s \n", FileName);
		return;
	}
	if (func_id_ < 23) {
		OShift_.resize(nx_);
		for (int i = 0; i < nx_; i++) {
			fscanf(fpt, "%lf", &OShift_[i]);
		}
	}
	else {
		OShift_.resize(nx_ * cf_num_);
		for (int i = 0; i < cf_num_ - 1; i++) {
			for (int j = 0; j < nx_; j++) {
				fscanf(fpt, "%lf", &OShift_[i * nx_ + j]);
			}
			fscanf(fpt, "%*[^] % *c"); // 跳過註解行
		}
		for (int j = 0; j < nx_; j++) {
			fscanf(fpt, "%lf", &OShift_[(cf_num_ - 1) * nx_ + j]);
		}
	}
	fclose(fpt);


	// === 讀取 shuffle_data（只在部分函數需要）===
	if ((func_id_ >= 17 && func_id_ <= 22) || func_id_ == 29 || func_id_ == 30) {
		sprintf(FileName, "input_data/shuffle_data_%d_D%d.txt", func_id_, nx_);
		fpt = fopen(FileName, "r");
		if (fpt == NULL) {
			printf("\n Error: Cannot open input file %s \n", FileName);
			return;
		}
		if (func_id_ >= 17 && func_id_ <= 22) {
			SS_.resize(nx_);
			for (int i = 0; i < nx_; i++) {
				fscanf(fpt, "%d", &SS_[i]);
			}
		}
		else if (func_id_ == 29 || func_id_ == 30) {
			SS_.resize(nx_ * cf_num_);
			for (int i = 0; i < nx_ * cf_num_; i++) {
				fscanf(fpt, "%d", &SS_[i]);
			}
		}
		fclose(fpt);
	}
}

void Cec14TestFunc::alloc_buffers() {
	y_.resize(nx_);
	z_.resize(nx_);
	x_bound_.resize(nx_, 100.0); // 預設邊界為 ±100
}

/* 評估函數公式實際內容 */
void Cec14TestFunc::sphere_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Sphere */
{
	int i;
	f[0] = 0.0;
	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */
	for (i = 0; i < nx; i++)
	{
		f[0] += z_[i] * z_[i];
	}

}

void Cec14TestFunc::ellips_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Ellipsoidal */
{
	int i;
	f[0] = 0.0;
	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */
	for (i = 0; i < nx; i++)
	{
		f[0] += pow(10.0, 6.0 * i / (nx - 1)) * z_[i] * z_[i];
	}
}

void Cec14TestFunc::bent_cigar_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Bent_Cigar */
{
	int i;
	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	f[0] = z_[0] * z_[0];
	for (i = 1; i < nx; i++)
	{
		f[0] += pow(10.0, 6.0) * z_[i] * z_[i];
	}


}

void Cec14TestFunc::discus_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Discus */
{
	int i;
	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */
	f[0] = pow(10.0, 6.0) * z_[0] * z_[0];
	for (i = 1; i < nx; i++)
	{
		f[0] += z_[i] * z_[i];
	}
}

void Cec14TestFunc::dif_powers_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Different Powers */
{
	int i;
	f[0] = 0.0;
	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		f[0] += pow(fabs(z_[i]), 2 + 4 * i / (nx - 1));
	}
	f[0] = pow(f[0], 0.5);
}

void Cec14TestFunc::rosenbrock_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Rosenbrock's */
{
	int i;
	double tmp1, tmp2;
	f[0] = 0.0;
	sr_func(x, z_.data(), nx, Os, Mr, 2.048 / 100.0, s_flag, r_flag); /* shift and rotate */
	z_[0] += 1.0;//shift to orgin
	for (i = 0; i < nx - 1; i++)
	{
		z_[i + 1] += 1.0;//shift to orgin
		tmp1 = z_[i] * z_[i] - z_[i + 1];
		tmp2 = z_[i] - 1.0;
		f[0] += 100.0 * tmp1 * tmp1 + tmp2 * tmp2;
	}
}

void Cec14TestFunc::schaffer_F7_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Schwefel's 1.2  */
{
	int i;
	double tmp;
	f[0] = 0.0;
	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */
	for (i = 0; i < nx - 1; i++)
	{
		z_[i] = pow(y_[i] * y_[i] + y_[i + 1] * y_[i + 1], 0.5);
		tmp = sin(50.0 * pow(z_[i], 0.2));
		f[0] += pow(z_[i], 0.5) + pow(z_[i], 0.5) * tmp * tmp;
	}
	f[0] = f[0] * f[0] / (nx - 1) / (nx - 1);
}

void Cec14TestFunc::ackley_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Ackley's  */
{
	int i;
	double sum1, sum2;
	sum1 = 0.0;
	sum2 = 0.0;

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		sum1 += z_[i] * z_[i];
		sum2 += cos(2.0 * PI * z_[i]);
	}
	sum1 = -0.2 * sqrt(sum1 / nx);
	sum2 /= nx;
	f[0] = E - 20.0 * exp(sum1) - exp(sum2) + 20.0;
}

void Cec14TestFunc::weierstrass_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Weierstrass's  */
{
	int i, j, k_max;
	double sum, sum2, a, b;
	a = 0.5;
	b = 3.0;
	k_max = 20;
	f[0] = 0.0;

	sr_func(x, z_.data(), nx, Os, Mr, 0.5 / 100.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		sum = 0.0;
		sum2 = 0.0;
		for (j = 0; j <= k_max; j++)
		{
			sum += pow(a, j) * cos(2.0 * PI * pow(b, j) * (z_[i] + 0.5));
			sum2 += pow(a, j) * cos(2.0 * PI * pow(b, j) * 0.5);
		}
		f[0] += sum;
	}
	f[0] -= nx * sum2;
}

void Cec14TestFunc::griewank_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Griewank's  */
{
	int i;
	double s, p;
	s = 0.0;
	p = 1.0;

	sr_func(x, z_.data(), nx, Os, Mr, 600.0 / 100.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		s += z_[i] * z_[i];
		p *= cos(z_[i] / sqrt(1.0 + i));
	}
	f[0] = 1.0 + s / 4000.0 - p;
}

void Cec14TestFunc::rastrigin_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Rastrigin's  */
{
	int i;
	f[0] = 0.0;

	sr_func(x, z_.data(), nx, Os, Mr, 5.12 / 100.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		f[0] += (z_[i] * z_[i] - 10.0 * cos(2.0 * PI * z_[i]) + 10.0);
	}
}

void Cec14TestFunc::step_rastrigin_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Noncontinuous Rastrigin's  */
{
	int i;
	f[0] = 0.0;
	for (i = 0; i < nx; i++)
	{
		if (fabs(y_[i] - Os[i]) > 0.5)
			y_[i] = Os[i] + floor(2 * (y_[i] - Os[i]) + 0.5) / 2;
	}

	sr_func(x, z_.data(), nx, Os, Mr, 5.12 / 100.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		f[0] += (z_[i] * z_[i] - 10.0 * cos(2.0 * PI * z_[i]) + 10.0);
	}
}

void Cec14TestFunc::schwefel_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Schwefel's  */
{
	int i;
	double tmp;
	f[0] = 0.0;

	sr_func(x, z_.data(), nx, Os, Mr, 1000.0 / 100.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		z_[i] += 4.209687462275036e+002;
		if (z_[i] > 500)
		{
			f[0] -= (500.0 - fmod(z_[i], 500)) * sin(pow(500.0 - fmod(z_[i], 500), 0.5));
			tmp = (z_[i] - 500.0) / 100;
			f[0] += tmp * tmp / nx;
		}
		else if (z_[i] < -500)
		{
			f[0] -= (-500.0 + fmod(fabs(z_[i]), 500)) * sin(pow(500.0 - fmod(fabs(z_[i]), 500), 0.5));
			tmp = (z_[i] + 500.0) / 100;
			f[0] += tmp * tmp / nx;
		}
		else
			f[0] -= z_[i] * sin(pow(fabs(z_[i]), 0.5));
	}
	f[0] += 4.189828872724338e+002 * nx;

}

void Cec14TestFunc::katsuura_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Katsuura  */
{
	int i, j;
	double temp, tmp1, tmp2, tmp3;
	f[0] = 1.0;
	tmp3 = pow(1.0 * nx, 1.2);

	sr_func(x, z_.data(), nx, Os, Mr, 5.0 / 100.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		temp = 0.0;
		for (j = 1; j <= 32; j++)
		{
			tmp1 = pow(2.0, j);
			tmp2 = tmp1 * z_[i];
			temp += fabs(tmp2 - floor(tmp2 + 0.5)) / tmp1;
		}
		f[0] *= pow(1.0 + (i + 1) * temp, 10.0 / tmp3);
	}
	tmp1 = 10.0 / nx / nx;
	f[0] = f[0] * tmp1 - tmp1;

}

void Cec14TestFunc::bi_rastrigin_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Lunacek Bi_rastrigin Function */
{
	int i;
	double mu0 = 2.5, d = 1.0, s, mu1, tmp, tmp1, tmp2;
	double* tmpx;
	tmpx = (double*)malloc(sizeof(double) * nx);
	s = 1.0 - 1.0 / (2.0 * pow(nx + 20.0, 0.5) - 8.2);
	mu1 = -pow((mu0 * mu0 - d) / s, 0.5);

	if (s_flag == 1)
		shiftfunc(x, y_.data(), nx, Os);
	else
	{
		for (i = 0; i < nx; i++)//shrink to the orginal search range
		{
			y_[i] = x[i];
		}
	}
	for (i = 0; i < nx; i++)//shrink to the orginal search range
	{
		y_[i] *= 10.0 / 100.0;
	}

	for (i = 0; i < nx; i++)
	{
		tmpx[i] = 2 * y_[i];
		if (Os[i] < 0.0)
			tmpx[i] *= -1.;
	}
	for (i = 0; i < nx; i++)
	{
		z_[i] = tmpx[i];
		tmpx[i] += mu0;
	}
	tmp1 = 0.0; tmp2 = 0.0;
	for (i = 0; i < nx; i++)
	{
		tmp = tmpx[i] - mu0;
		tmp1 += tmp * tmp;
		tmp = tmpx[i] - mu1;
		tmp2 += tmp * tmp;
	}
	tmp2 *= s;
	tmp2 += d * nx;
	tmp = 0.0;

	if (r_flag == 1)
	{
		rotatefunc(z_.data(), y_.data(), nx, Mr);
		for (i = 0; i < nx; i++)
		{
			tmp += cos(2.0 * PI * y_[i]);
		}
		if (tmp1 < tmp2)
			f[0] = tmp1;
		else
			f[0] = tmp2;
		f[0] += 10.0 * (nx - tmp);
	}
	else
	{
		for (i = 0; i < nx; i++)
		{
			tmp += cos(2.0 * PI * z_[i]);
		}
		if (tmp1 < tmp2)
			f[0] = tmp1;
		else
			f[0] = tmp2;
		f[0] += 10.0 * (nx - tmp);
	}

	free(tmpx);
}

void Cec14TestFunc::grie_rosen_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Griewank-Rosenbrock  */
{
	int i;
	double temp, tmp1, tmp2;
	f[0] = 0.0;

	sr_func(x, z_.data(), nx, Os, Mr, 5.0 / 100.0, s_flag, r_flag); /* shift and rotate */

	z_[0] += 1.0;//shift to orgin
	for (i = 0; i < nx - 1; i++)
	{
		z_[i + 1] += 1.0;//shift to orgin
		tmp1 = z_[i] * z_[i] - z_[i + 1];
		tmp2 = z_[i] - 1.0;
		temp = 100.0 * tmp1 * tmp1 + tmp2 * tmp2;
		f[0] += (temp * temp) / 4000.0 - cos(temp) + 1.0;
	}
	tmp1 = z_[nx - 1] * z_[nx - 1] - z_[0];
	tmp2 = z_[nx - 1] - 1.0;
	temp = 100.0 * tmp1 * tmp1 + tmp2 * tmp2;
	f[0] += (temp * temp) / 4000.0 - cos(temp) + 1.0;
}

void Cec14TestFunc::escaffer6_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* Expanded Scaffer’s F6  */
{
	int i;
	double temp1, temp2;

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	f[0] = 0.0;
	for (i = 0; i < nx - 1; i++)
	{
		temp1 = sin(sqrt(z_[i] * z_[i] + z_[i + 1] * z_[i + 1]));
		temp1 = temp1 * temp1;
		temp2 = 1.0 + 0.001 * (z_[i] * z_[i] + z_[i + 1] * z_[i + 1]);
		f[0] += 0.5 + (temp1 - 0.5) / (temp2 * temp2);
	}
	temp1 = sin(sqrt(z_[nx - 1] * z_[nx - 1] + z_[0] * z_[0]));
	temp1 = temp1 * temp1;
	temp2 = 1.0 + 0.001 * (z_[nx - 1] * z_[nx - 1] + z_[0] * z_[0]);
	f[0] += 0.5 + (temp1 - 0.5) / (temp2 * temp2);
}

void Cec14TestFunc::happycat_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* HappyCat, provdided by Hans-Georg Beyer (HGB) */
/* original global optimum: [-1,-1,...,-1] */
{
	int i;
	double alpha, r2, sum_z;
	alpha = 1.0 / 8.0;

	sr_func(x, z_.data(), nx, Os, Mr, 5.0 / 100.0, s_flag, r_flag); /* shift and rotate */

	r2 = 0.0;
	sum_z = 0.0;
	for (i = 0; i < nx; i++)
	{
		z_[i] = z_[i] - 1.0;//shift to orgin
		r2 += z_[i] * z_[i];
		sum_z += z_[i];
	}
	f[0] = pow(fabs(r2 - nx), 2 * alpha) + (0.5 * r2 + sum_z) / nx + 0.5;
}

void Cec14TestFunc::hgbat_func(double* x, double* f, int nx, const double* Os, const double* Mr, int s_flag, int r_flag) const /* HGBat, provdided by Hans-Georg Beyer (HGB)*/
/* original global optimum: [-1,-1,...,-1] */
{
	int i;
	double alpha, r2, sum_z;
	alpha = 1.0 / 4.0;

	sr_func(x, z_.data(), nx, Os, Mr, 5.0 / 100.0, s_flag, r_flag); /* shift and rotate */

	r2 = 0.0;
	sum_z = 0.0;
	for (i = 0; i < nx; i++)
	{
		z_[i] = z_[i] - 1.0;//shift to orgin
		r2 += z_[i] * z_[i];
		sum_z += z_[i];
	}
	f[0] = pow(fabs(pow(r2, 2.0) - pow(sum_z, 2.0)), 2 * alpha) + (0.5 * r2 + sum_z) / nx + 0.5;
}

void Cec14TestFunc::hf01(double* x, double* f, int nx, const double* Os, const double* Mr, const int* S, int s_flag, int r_flag) const /* Hybrid Function 1 */
{
	int i, tmp, cf_num = 3;
	double fit[3];
	int G[3], G_nx[3];
	double Gp[3] = { 0.3,0.3,0.4 };

	tmp = 0;
	for (i = 0; i < cf_num - 1; i++)
	{
		G_nx[i] = ceil(Gp[i] * nx);
		tmp += G_nx[i];
	}
	G_nx[cf_num - 1] = nx - tmp;
	G[0] = 0;
	for (i = 1; i < cf_num; i++)
	{
		G[i] = G[i - 1] + G_nx[i - 1];
	}

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		y_[i] = z_[S[i] - 1];
	}
	i = 0;
	schwefel_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 1;
	rastrigin_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 2;
	ellips_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] += fit[i];
	}
}

void Cec14TestFunc::hf02(double* x, double* f, int nx, const double* Os, const double* Mr, const int* S, int s_flag, int r_flag) const /* Hybrid Function 2 */
{
	int i, tmp, cf_num = 3;
	double fit[3];
	int G[3], G_nx[3];
	double Gp[3] = { 0.3,0.3,0.4 };

	tmp = 0;
	for (i = 0; i < cf_num - 1; i++)
	{
		G_nx[i] = ceil(Gp[i] * nx);
		tmp += G_nx[i];
	}
	G_nx[cf_num - 1] = nx - tmp;

	G[0] = 0;
	for (i = 1; i < cf_num; i++)
	{
		G[i] = G[i - 1] + G_nx[i - 1];
	}

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		y_[i] = z_[S[i] - 1];
	}
	i = 0;
	bent_cigar_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 1;
	hgbat_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 2;
	rastrigin_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);

	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] += fit[i];
	}
}

void Cec14TestFunc::hf03(double* x, double* f, int nx, const double* Os, const double* Mr, const int* S, int s_flag, int r_flag) const /* Hybrid Function 3 */
{
	int i, tmp, cf_num = 4;
	double fit[4];
	int G[4], G_nx[4];
	double Gp[4] = { 0.2,0.2,0.3,0.3 };

	tmp = 0;
	for (i = 0; i < cf_num - 1; i++)
	{
		G_nx[i] = ceil(Gp[i] * nx);
		tmp += G_nx[i];
	}
	G_nx[cf_num - 1] = nx - tmp;

	G[0] = 0;
	for (i = 1; i < cf_num; i++)
	{
		G[i] = G[i - 1] + G_nx[i - 1];
	}

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		y_[i] = z_[S[i] - 1];
	}
	i = 0;
	griewank_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 1;
	weierstrass_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 2;
	rosenbrock_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 3;
	escaffer6_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);

	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] += fit[i];
	}
}

void Cec14TestFunc::hf04(double* x, double* f, int nx, const double* Os, const double* Mr, const int* S, int s_flag, int r_flag) const /* Hybrid Function 4 */
{
	int i, tmp, cf_num = 4;
	double fit[4];
	int G[4], G_nx[4];
	double Gp[4] = { 0.2,0.2,0.3,0.3 };

	tmp = 0;
	for (i = 0; i < cf_num - 1; i++)
	{
		G_nx[i] = ceil(Gp[i] * nx);
		tmp += G_nx[i];
	}
	G_nx[cf_num - 1] = nx - tmp;

	G[0] = 0;
	for (i = 1; i < cf_num; i++)
	{
		G[i] = G[i - 1] + G_nx[i - 1];
	}

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		y_[i] = z_[S[i] - 1];
	}
	i = 0;
	hgbat_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 1;
	discus_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 2;
	grie_rosen_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 3;
	rastrigin_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);

	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] += fit[i];
	}
}
void Cec14TestFunc::hf05(double* x, double* f, int nx, const double* Os, const double* Mr, const int* S, int s_flag, int r_flag) const /* Hybrid Function 5 */
{
	int i, tmp, cf_num = 5;
	double fit[5];
	int G[5], G_nx[5];
	double Gp[5] = { 0.1,0.2,0.2,0.2,0.3 };

	tmp = 0;
	for (i = 0; i < cf_num - 1; i++)
	{
		G_nx[i] = ceil(Gp[i] * nx);
		tmp += G_nx[i];
	}
	G_nx[cf_num - 1] = nx - tmp;

	G[0] = 0;
	for (i = 1; i < cf_num; i++)
	{
		G[i] = G[i - 1] + G_nx[i - 1];
	}

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		y_[i] = z_[S[i] - 1];
	}
	i = 0;
	escaffer6_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 1;
	hgbat_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 2;
	rosenbrock_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 3;
	schwefel_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 4;
	ellips_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);

	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] += fit[i];
	}
}

void Cec14TestFunc::hf06(double* x, double* f, int nx, const double* Os, const double* Mr, const int* S, int s_flag, int r_flag) const /* Hybrid Function 6 */
{
	int i, tmp, cf_num = 5;
	double fit[5];
	int G[5], G_nx[5];
	double Gp[5] = { 0.1,0.2,0.2,0.2,0.3 };

	tmp = 0;
	for (i = 0; i < cf_num - 1; i++)
	{
		G_nx[i] = ceil(Gp[i] * nx);
		tmp += G_nx[i];
	}
	G_nx[cf_num - 1] = nx - tmp;

	G[0] = 0;
	for (i = 1; i < cf_num; i++)
	{
		G[i] = G[i - 1] + G_nx[i - 1];
	}

	sr_func(x, z_.data(), nx, Os, Mr, 1.0, s_flag, r_flag); /* shift and rotate */

	for (i = 0; i < nx; i++)
	{
		y_[i] = z_[S[i] - 1];
	}
	i = 0;
	katsuura_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 1;
	happycat_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 2;
	grie_rosen_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 3;
	schwefel_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	i = 4;
	ackley_func(&y_[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] += fit[i];
	}
}

void Cec14TestFunc::cf01(double* x, double* f, int nx, const double* Os, const double* Mr, int r_flag) const /* Composition Function 1 */
{
	int i, cf_num = 5;
	double fit[5];
	double delta[5] = { 10, 20, 30, 40, 50 };
	double bias[5] = { 0, 100, 200, 300, 400 };

	i = 0;
	rosenbrock_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+4;
	i = 1;
	ellips_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+10;
	i = 2;
	bent_cigar_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+30;
	i = 3;
	discus_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+10;
	i = 4;
	ellips_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, 0);
	fit[i] = 10000 * fit[i] / 1e+10;
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf02(double* x, double* f, int nx, const double* Os, const double* Mr, int r_flag) const /* Composition Function 2 */
{
	int i, cf_num = 3;
	double fit[3];
	double delta[3] = { 20,20,20 };
	double bias[3] = { 0, 100, 200 };

	i = 0;
	schwefel_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, 0);
	i = 1;
	rastrigin_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	i = 2;
	hgbat_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf03(double* x, double* f, int nx, const double* Os, const double* Mr, int r_flag) const /* Composition Function 3 */
{
	int i, cf_num = 3;
	double fit[3];
	double delta[3] = { 10,30,50 };
	double bias[3] = { 0, 100, 200 };
	i = 0;
	schwefel_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 4e+3;
	i = 1;
	rastrigin_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 1e+3;
	i = 2;
	ellips_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 1e+10;
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf04(double* x, double* f, int nx, const double* Os, const double* Mr, int r_flag) const /* Composition Function 4 */
{
	int i, cf_num = 5;
	double fit[5];
	double delta[5] = { 10,10,10,10,10 };
	double bias[5] = { 0, 100, 200, 300, 400 };
	i = 0;
	schwefel_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 4e+3;
	i = 1;
	happycat_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 1e+3;
	i = 2;
	ellips_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 1e+10;
	i = 3;
	weierstrass_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 400;
	i = 4;
	griewank_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 1000 * fit[i] / 100;
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf05(double* x, double* f, int nx, const double* Os, const double* Mr, int r_flag) const /* Composition Function 4 */
{
	int i, cf_num = 5;
	double fit[5];
	double delta[5] = { 10,10,10,20,20 };
	double bias[5] = { 0, 100, 200, 300, 400 };
	i = 0;
	hgbat_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1000;
	i = 1;
	rastrigin_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+3;
	i = 2;
	schwefel_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 4e+3;
	i = 3;
	weierstrass_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 400;
	i = 4;
	ellips_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+10;
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf06(double* x, double* f, int nx, const double* Os, const double* Mr, int r_flag) const /* Composition Function 6 */
{
	int i, cf_num = 5;
	double fit[5];
	double delta[5] = { 10,20,30,40,50 };
	double bias[5] = { 0, 100, 200, 300, 400 };
	i = 0;
	grie_rosen_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 4e+3;
	i = 1;
	happycat_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+3;
	i = 2;
	schwefel_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 4e+3;
	i = 3;
	escaffer6_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 2e+7;
	i = 4;
	ellips_func(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], 1, r_flag);
	fit[i] = 10000 * fit[i] / 1e+10;
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf07(double* x, double* f, int nx, const double* Os, const double* Mr, const int* SS, int r_flag) const /* Composition Function 7 */
{
	int i, cf_num = 3;
	double fit[3];
	double delta[3] = { 10,30,50 };
	double bias[3] = { 0, 100, 200 };
	i = 0;
	hf01(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], &SS[i * nx], 1, r_flag);
	i = 1;
	hf02(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], &SS[i * nx], 1, r_flag);
	i = 2;
	hf03(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], &SS[i * nx], 1, r_flag);
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}

void Cec14TestFunc::cf08(double* x, double* f, int nx, const double* Os, const double* Mr, const int* SS, int r_flag) const /* Composition Function 8 */
{
	int i, cf_num = 3;
	double fit[3];
	double delta[3] = { 10,30,50 };
	double bias[3] = { 0, 100, 200 };
	i = 0;
	hf04(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], &SS[i * nx], 1, r_flag);
	i = 1;
	hf05(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], &SS[i * nx], 1, r_flag);
	i = 2;
	hf06(x, &fit[i], nx, &Os[i * nx], &Mr[i * nx * nx], &SS[i * nx], 1, r_flag);
	cf_cal(x, f, nx, Os, delta, bias, fit, cf_num);
}


void Cec14TestFunc::shiftfunc(double* x, double* xshift, int nx, const double* Os) const
{
	int i;
	for (i = 0; i < nx; i++)
	{
		xshift[i] = x[i] - Os[i];
	}
}

void Cec14TestFunc::rotatefunc(double* x, double* xrot, int nx, const double* Mr) const
{
	int i, j;
	for (i = 0; i < nx; i++)
	{
		xrot[i] = 0;
		for (j = 0; j < nx; j++)
		{
			xrot[i] = xrot[i] + x[j] * Mr[i * nx + j];
		}
	}
}

void Cec14TestFunc::sr_func(double* x, double* sr_x, int nx, const double* Os, const double* Mr, double sh_rate, int s_flag, int r_flag) const /* shift and rotate */
{
	int i;
	if (s_flag == 1)
	{
		if (r_flag == 1)
		{
			shiftfunc(x, y_.data(), nx, Os);
			for (i = 0; i < nx; i++)//shrink to the original search range
			{
				y_[i] = y_[i] * sh_rate;
			}
			rotatefunc(y_.data(), sr_x, nx, Mr);
		}
		else
		{
			shiftfunc(x, sr_x, nx, Os);
			for (i = 0; i < nx; i++)//shrink to the original search range
			{
				sr_x[i] = sr_x[i] * sh_rate;
			}
		}
	}
	else
	{

		if (r_flag == 1)
		{
			for (i = 0; i < nx; i++)//shrink to the original search range
			{
				y_[i] = x[i] * sh_rate;
			}
			rotatefunc(y_.data(), sr_x, nx, Mr);
		}
		else
			for (i = 0; i < nx; i++)//shrink to the original search range
			{
				sr_x[i] = x[i] * sh_rate;
			}
	}
}

void Cec14TestFunc::asyfunc(double* x, double* xasy, int nx, double beta) const /* Asymmetry Function */
{
	int i;
	for (i = 0; i < nx; i++)
	{
		if (x[i] > 0)
			xasy[i] = pow(x[i], 1.0 + beta * i / (nx - 1) * pow(x[i], 0.5));
	}
}

void Cec14TestFunc::oszfunc(double* x, double* xosz, int nx) const
{
	int i, sx;
	double c1, c2, xx;
	for (i = 0; i < nx; i++)
	{
		if (i == 0 || i == nx - 1)
		{
			if (x[i] != 0)
				xx = log(fabs(x[i]));
			if (x[i] > 0)
			{
				c1 = 10;
				c2 = 7.9;
			}
			else
			{
				c1 = 5.5;
				c2 = 3.1;
			}
			if (x[i] > 0)
				sx = 1;
			else if (x[i] == 0)
				sx = 0;
			else
				sx = -1;
			xosz[i] = sx * exp(xx + 0.049 * (sin(c1 * xx) + sin(c2 * xx)));
		}
		else
			xosz[i] = x[i];
	}
}

void Cec14TestFunc::cf_cal(double* x, double* f, int nx, const double* Os, const double* delta, const double* bias, double* fit, int cf_num) const
{
	int i, j;
	double* w;
	double w_max = 0, w_sum = 0;
	w = (double*)malloc(cf_num * sizeof(double));
	for (i = 0; i < cf_num; i++)
	{
		fit[i] += bias[i];
		w[i] = 0;
		for (j = 0; j < nx; j++)
		{
			w[i] += pow(x[j] - Os[i * nx + j], 2.0);
		}
		if (w[i] != 0)
			w[i] = pow(1.0 / w[i], 0.5) * exp(-w[i] / 2.0 / nx / pow(delta[i], 2.0));
		else
			w[i] = INF;
		if (w[i] > w_max)
			w_max = w[i];
	}

	for (i = 0; i < cf_num; i++)
	{
		w_sum = w_sum + w[i];
	}
	if (w_max == 0)
	{
		for (i = 0; i < cf_num; i++)
			w[i] = 1;
		w_sum = cf_num;
	}
	f[0] = 0.0;
	for (i = 0; i < cf_num; i++)
	{
		f[0] = f[0] + w[i] / w_sum * fit[i];
	}
	free(w);
}