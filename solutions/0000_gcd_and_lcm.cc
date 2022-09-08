using namespace std;

/**
 * @brief 0000 GCD and LCM (Greatest Common Divisor and Least Common Multiple)
 * 最大公因数与最小公倍数
 *
 */
// 最大公因数，辗转相除法
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// 最小公倍数，辗转相除法
int lcm(int a, int b) { return a * b / gcd(a, b); }

// 最大公因数，扩展欧几里得算法
// todo
