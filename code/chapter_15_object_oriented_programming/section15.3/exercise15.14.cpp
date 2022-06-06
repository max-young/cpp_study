// Exercise 15.14:
// Given the classes from the previous exercise and the following objects,
// determine which function is called at run time:
// base bobj;
// base *bp1 = &bobj;
// base &br1 = bobj;
// derived dobj;
// base *bp2 = &dobj;
// base &br2 = dobj;
// (a) bobj.print();
// base print
// (b) dobj.print();
// derived print
// (c) bp1->name();
// base name
// (d) bp2->name();
// base name
// (e) br1.print();
// base print
// (f) br2.print();
// derived print