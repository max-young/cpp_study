// Exercise 15.11:  
// Add a virtual debug function to your Quote class hierarchy
// that displays the data members of the respective classes.

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Quote
{
public:
  Quote() = default;
  Quote(const string &bookNo, double price) : bookNo_(bookNo), price_(price){};
  string getIsbn() const { return bookNo_; };
  virtual double getPrice(size_t n) const { return n * price_; };
  virtual ~Quote() = default; // virtual destructor通常需要定义, 尽管是default
  virtual void debug()
  {
    cout << this->bookNo_ << endl;
    cout << this->price_ << endl;
  }

private:
  string bookNo_;

protected:
  double price_ = 0.0;
};

class BulkQuote : public Quote
{
public:
  BulkQuote() = default;
  BulkQuote(const string &bookNo, double price, size_t minQty, double discount) : Quote(bookNo, price), minQty_(minQty), discount_(discount){};
  double getPrice(size_t n) const override { return n * price_ * (n >= minQty_ ? (1 - discount_) : 1); };
  ~BulkQuote() override = default;
  virtual void debug() override
  {
    Quote::debug();
    cout << this->minQty_ << endl;
    cout << this->discount_ << endl;
  }

private:
  size_t minQty_ = 0;
  double discount_ = 0.0;
};

double printTotal(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.getPrice(n);
  os << "ISBN: " << item.getIsbn() << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}

int main()
{
  Quote q("123", 10);
  BulkQuote bq("456", 10, 10, 0.5);
  q.debug();
  bq.debug();

  return 0;
}