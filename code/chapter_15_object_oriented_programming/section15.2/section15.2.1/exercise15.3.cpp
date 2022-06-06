// Exercise 15.3: Define your own versions of the Quote class and the print_total function.

#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::ostream;

class Quote
{
public:
  Quote() = default;
  Quote(string bookNo, double price) : bookNo_(bookNo), price_(price) {};
  string getIsbn() const { return bookNo_; };
  virtual double getPrice(size_t n) const { return n * price_; };
  
  virtual ~Quote() = default;

private:
  string bookNo_;

protected:
  double price_ = 0.0;
};

double printTotal(ostream &os, const Quote &item, size_t n)
{
  double ret = item.getPrice(n);
  os << "ISBN: " << item.getIsbn() << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main()
{
  Quote q("12345", 10.0);
  printTotal(cout, q, 10);
  return 0;
}