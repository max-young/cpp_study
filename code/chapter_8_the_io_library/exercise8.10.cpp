Exercise 8.10:
Write a program to store each line from a file in a vector<string>.
Now use an istringstream to read each element from the vector a word at a time.

int main()
{
  vector<string> lines;
  string line;
  ifstream ifs("resources/data.txt")
  while (get_line(ifs, line))
  {
    lines.push_back(line);
  }

  
  
}