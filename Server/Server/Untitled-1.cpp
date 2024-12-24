#include <iostream>
#include <memory>

// Định nghĩa kiểu con trỏ thông minh cho các đối tượng Expression
using ExprPtr = std::shared_ptr<class Expression>;

// Lớp cơ sở trừu tượng Expression
class Expression {
public:
    virtual ~Expression() = default;
    virtual double eval() const = 0;  // Phương thức ảo để tính giá trị
};

// Lớp Number đại diện cho số học
class Number : public Expression {
private:
    double mValue;  // Giá trị của số

public:
    explicit Number(double value) : mValue(value) {}

    double eval() const override {
        return mValue;
    }
};

// Lớp biểu thức đơn (UnaryExpression), kế thừa từ Expression
class UnaryExpression : public Expression {
protected:
    ExprPtr mSubExpr;  // Biểu thức con

public:
    explicit UnaryExpression(ExprPtr subExpr) : mSubExpr(std::move(subExpr)) {}
};

// Lớp Negation kế thừa từ UnaryExpression (nghịch đảo)
class Negation : public UnaryExpression {
public:
    explicit Negation(ExprPtr subExpr) : UnaryExpression(std::move(subExpr)) {}

    double eval() const override {
        return -mSubExpr->eval();
    }
};

// Lớp BinaryExpression (Biểu thức nhị phân) kế thừa từ Expression
class BinaryExpression : public Expression {
protected:
    ExprPtr mLeftExpr;  // Biểu thức bên trái
    ExprPtr mRightExpr; // Biểu thức bên phải

public:
    BinaryExpression(ExprPtr left, ExprPtr right) 
        : mLeftExpr(std::move(left)), mRightExpr(std::move(right)) {}
};

// Lớp Sum (tổng) kế thừa từ BinaryExpression
class Sum : public BinaryExpression {
public:
    Sum(ExprPtr left, ExprPtr right) : BinaryExpression(std::move(left), std::move(right)) {}

    double eval() const override {
        return mLeftExpr->eval() + mRightExpr->eval();
    }
};

// 2. Lớp Difference (hiệu) kế thừa từ BinaryExpression
class Difference : public BinaryExpression {
public:
    Difference(ExprPtr left, ExprPtr right) : BinaryExpression(std::move(left), std::move(right)) {}

    double eval() const override {
        return mLeftExpr->eval() - mRightExpr->eval();
    }
};

// 3. Lớp Product (tích) kế thừa từ BinaryExpression
class Product : public BinaryExpression {
public:
    Product(ExprPtr left, ExprPtr right) : BinaryExpression(std::move(left), std::move(right)) {}

    double eval() const override {
        return mLeftExpr->eval() * mRightExpr->eval();
    }
};

// 4. Lớp Division (thương) kế thừa từ BinaryExpression
class Division : public BinaryExpression {
public:
    Division(ExprPtr left, ExprPtr right) : BinaryExpression(std::move(left), std::move(right)) {}

    double eval() const override {
        return mLeftExpr->eval() / mRightExpr->eval();
    }
};

int main() {
    // 2. Tạo cây biểu thức (-1 + 2 + (-3))
    ExprPtr expr1 = std::make_shared<Sum>(
        std::make_shared<Sum>(
            std::make_shared<Negation>(std::make_shared<Number>(1)), 
            std::make_shared<Number>(2)
        ),
        std::make_shared<Negation>(std::make_shared<Number>(3))
    );
    
    std::cout << "Gia tri cua bieu thuc (-1 + 2 + (-3)): " << expr1->eval() << std::endl;

    // 4. Tạo cây biểu thức (-1 * 2 + (3 - 4) / 5)
    ExprPtr expr2 = std::make_shared<Sum>(
        std::make_shared<Product>(
            std::make_shared<Negation>(std::make_shared<Number>(1)),
            std::make_shared<Number>(2)
        ),
        std::make_shared<Division>(
            std::make_shared<Difference>(
                std::make_shared<Number>(3),
                std::make_shared<Number>(4)
            ),
            std::make_shared<Number>(5)
        )
    );

    std::cout << "Gia tri cua bieu thuc (-1 * 2 + (3 - 4) / 5): " << expr2->eval() << std::endl;

    return 0;
}
