#include <string>

using std::string;

class Quote
{
public:
  string getIsbn() const;
  virtual double getPrice(size_t n) const;
};

class BulkQuote : public Quote
{
public:
  double getPrice(size_t n) const override;
};

double printTotal(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.getPrice(n);
  os << "ISBN: " << item.getIsbn() << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}

int main()
{
  return 0;
}