#include <iostream>

// Question 1: Define a class Complex to represent a complex number
class Complex {
private:
    int a; // real part
    int b; // imaginary part

public:
    void setData(int real, int imag) {
        a = real;
        b = imag;
    }

    void showData() const {
        std::cout << "Complex number: " << a << " + " << b << "i" << std::endl;
    }

    Complex add(const Complex& c) const { // const and reference
        Complex result;
        result.a = a + c.a;
        result.b = b + c.b;
        return result;
    }

    Complex subtract(const Complex& c) const { // const and reference
        Complex result;
        result.a = a - c.a;
        result.b = b - c.b;
        return result;
    }

    Complex multiply(const Complex& c) const { // const and reference
        Complex result;
        result.a = a * c.a - b * c.b;
        result.b = a * c.b + b * c.a;
        return result;
    }
};

// Question 2: Define a class Time to represent a time
class Time {
private:
    int h; // hours
    int m; // minutes
    int s; // seconds

public:
    void setTime(int hours, int minutes, int seconds) {
        h = hours;
        m = minutes;
        s = seconds;
        normalize();
    }

    void showTime() const {
        std::cout << "Time: " << h << "h " << m << "m " << s << "s" << std::endl;
    }

    void normalize() {
        if (s >= 60) {
            m += s / 60;
            s %= 60;
        }
        if (m >= 60) {
            h += m / 60;
            m %= 60;
        }
    }

    Time add(const Time& t) const { // const and reference
        Time result;
        result.h = h + t.h;
        result.m = m + t.m;
        result.s = s + t.s;
        result.normalize();
        return result;
    }

    bool is_greater(const Time& t) const { // const and reference
        if (h > t.h) return true;
        if (h == t.h && m > t.m) return true;
        if (h == t.h && m == t.m && s > t.s) return true;
        return false;
    }
};

// Question 3: Define a class TestResult with properties roll_no, right, wrong, net_score
class TestResult {
private:
    int roll_no;
    int right;
    int wrong;
    float net_score;
    float right_weightage;
    float wrong_weightage;

public:
    void setProperties(int rn, int r, int w, float rw, float ww) {
        roll_no = rn;
        right = r;
        wrong = w;
        right_weightage = rw;
        wrong_weightage = ww;
        calculateNetScore();
    }

    void calculateNetScore() {
        net_score = (right * right_weightage) - (wrong * wrong_weightage);
    }

    void showProperties() const {
        std::cout << "Roll No: " << roll_no << std::endl;
        std::cout << "Right Answers: " << right << std::endl;
        std::cout << "Wrong Answers: " << wrong << std::endl;
        std::cout << "Net Score: " << net_score << std::endl;
    }

    void setRightWeightage(float rw) {
        right_weightage = rw;
        calculateNetScore();
    }

    void setWrongWeightage(float ww) {
        wrong_weightage = ww;
        calculateNetScore();
    }

    int getRollNo() const { return roll_no; }
    int getRight() const { return right; }
    int getWrong() const { return wrong; }
    float getNetScore() const { return net_score; }
    float getRightWeightage() const { return right_weightage; }
    float getWrongWeightage() const { return wrong_weightage; }
};

// Question 5: Define a class Matrix to represent a 3x3 order matrix
class Matrix {
private:
    int data[3][3];

public:
    void setData(int d[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = d[i][j];
            }
        }
    }

    void showData() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(const Matrix& m) const { // const and reference
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }

    Matrix sub(const Matrix& m) const { // const and reference
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& m) const { // const and reference
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose() const { // const
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    bool is_singular() const { // const
        int determinant = data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
                          data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
                          data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
        return determinant == 0;
    }
};

// Function to input data for TestResult (for Question 3 & 4)
void inputTestResultData(TestResult& tr) {
    int roll_no, right, wrong;
    float right_weightage, wrong_weightage;
    std::cout << "Enter roll no: ";
    std::cin >> roll_no;
    std::cout << "Enter number of right answers: ";
    std::cin >> right;
    std::cout << "Enter number of wrong answers: ";
    std::cin >> wrong;
    std::cout << "Enter weightage for right answers: ";
    std::cin >> right_weightage;
    std::cout << "Enter weightage for wrong answers: ";
    std::cin >> wrong_weightage;
    tr.setProperties(roll_no, right, wrong, right_weightage, wrong_weightage);
}

// Function to input data for Matrix (for Question 5)
void inputMatrixData(Matrix& m) {
    int data[3][3];
    std::cout << "Enter matrix elements (3x3):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> data[i][j];
        }
    }
    m.setData(data);
}

int main() {
    // Example usage of Complex class (Question 1)
    Complex c1, c2, c3;
    int real, imag;
    std::cout << "Enter real and imaginary parts of first complex number: ";
    std::cin >> real >> imag;
    c1.setData(real, imag);
    std::cout << "Enter real and imaginary parts of second complex number: ";
    std::cin >> real >> imag;
    c2.setData(real, imag);

    c3 = c1.add(c2);
    c3.showData();

    c3 = c1.subtract(c2);
    c3.showData();

    c3 = c1.multiply(c2);
    c3.showData();

    // Example usage of Time class (Question 2)
    Time t1, t2, t3;
    int hours, minutes, seconds;
    std::cout << "Enter hours, minutes, and seconds of first time: ";
    std::cin >> hours >> minutes >> seconds;
    t1.setTime(hours, minutes, seconds);
    std::cout << "Enter hours, minutes, and seconds of second time: ";
    std::cin >> hours >> minutes >> seconds;
    t2.setTime(hours, minutes, seconds);

    t3 = t1.add(t2);
    t3.showTime();
    std::cout << (t1.is_greater(t2) ? "First time is greater" : "Second time is greater") << std::endl;

    // Example usage of TestResult class (Question 3 & 4)
    TestResult testResults[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter details for student " << i + 1 << ":\n";
        inputTestResultData(testResults[i]);
    }

    // Sort TestResult objects by net_score
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (testResults[i].getNetScore() < testResults[j].getNetScore()) {
                TestResult temp = testResults[i];
                testResults[i] = testResults[j];
                testResults[j] = temp;
            }
        }
    }

    // Display sorted TestResult objects
    for (int i = 0; i < 5; ++i) {
        testResults[i].showProperties();
    }

    // Example usage of Matrix class (Question 5)
    Matrix m1, m2, m3;
    std::cout << "Enter data for first matrix:\n";
    inputMatrixData(m1);
    std::cout << "Enter data for second matrix:\n";
    inputMatrixData(m2);

    m3 = m1.add(m2);
    std::cout << "Addition of matrices:\n";
    m3.showData();

    m3 = m1.sub(m2);
    std::cout << "Subtraction of matrices:\n";
    m3.showData();

    m3 = m1.multiply(m2);
    std::cout << "Multiplication of matrices:\n";
    m3.showData();

    m3 = m1.transpose();
    std::cout << "Transpose of first matrix:\n";
    m3.showData();

    std::cout << (m1.is_singular() ? "First matrix is singular" : "First matrix is not singular") << std::endl;

    return 0;
}

