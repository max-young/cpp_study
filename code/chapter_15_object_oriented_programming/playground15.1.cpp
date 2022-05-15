#include <string>

// using std::size_t;
using std::string;

class Quote
{
public:
  string get_isbn() const;
  virtual double get_price(size_t n) const;
};

class BulkQuote : public Quote
{
public:
  double get_price(size_t n) const override;
};

double printTotal(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.get_price(n);
  os << "ISBN: " << item.get_isbn() << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}

int main()
{
  return 0;
}