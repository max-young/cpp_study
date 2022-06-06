Exercise  9.1:
Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?
Explain the rationale for your choice.
If there is no reason to prefer one or another container, explain why not.
(a) Read a fixed number of words,
  inserting them in the container alphabetically as they are entered.
  We’ll see in the next chapter that associative containers are better suited to this problem.

  list

(b) Read an unknown number of words.
  Always insert new words at the back.
  Remove the next value from the front.

  deque

(c) Read an unknown number of integers from a file.
  Sort the numbers and then print them to standard output.

  vector and sort