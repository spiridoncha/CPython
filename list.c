#include <Python.h>
int main(int argc, char *argv[])
{
	int i, s, e, r;
	char *res;
	PyObject *expr[3];
	int len = argc - 3;
	if (argc < 5)
	{
		fprintf(stderr, "Usage: <List> <start> <end> <repeat> , where List = {<String>}\n\n\
Print List[start:end]*repeat");
		exit(0);
	}
	s = atoi(argv[len]);
	e = atoi(argv[len+1]);
	r = atoi(argv[len+2]);
	expr[0] = PyList_New(0);
	for(i=1;i<len;++i)
	{
		PyList_Append(expr[0], PyString_FromString(argv[i]));
	}
	expr[1] = PyList_GetSlice(expr[0], s, e);
	expr[2] = PySequence_Repeat(expr[1], r);
	for(i=0;i<len;++i)
	{
		res = PyString_AsString(PyList_GetItem(expr[2], i));
		printf("%s\n", res);
	}
	for(i=0;i<3;++i)
	{
		Py_CLEAR(expr[i]);
	}
	return 0;
}
