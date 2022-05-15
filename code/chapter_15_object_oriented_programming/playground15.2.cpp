#include <string>

using std::string;

class Quote
{
public:
  Quote() = default;
  string getIsbn() const { return bookNo_; };
  virtual double getPrice(size_t n) const { return n * price_; };
  virtual ~Quote() = default;

private:
  string bookNo_;

protected:
  double price_ = 0.0;
};

int main()
{
  return 0;
}