s:
	oj-bundle -I . a.cpp > submit.cpp
a:
	oj-bundle -I . a.cpp > submit.cpp
	g++ a.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -I . -H -o a
	./a
a1:
	oj-bundle -I . a.cpp > submit.cpp
	g++ a.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -I . -H -o a
	./a < in1.txt
a2:
	oj-bundle -I . a.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
a3:
	oj-bundle -I . a.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
a4:
	oj-bundle -I . a.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
b:
	oj-bundle -I . b.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a
b1:
	oj-bundle -I . b.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
b2:
	oj-bundle -I . b.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
b3:
	oj-bundle -I . b.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
b4:
	oj-bundle -I . b.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
c:
	oj-bundle -I . c.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a
c1:
	oj-bundle -I . c.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
c2:
	oj-bundle -I . c.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
c3:
	oj-bundle -I . c.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
c4:
	oj-bundle -I . c.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
d:
	oj-bundle -I . d.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a
d1:
	oj-bundle -I . d.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
d2:
	oj-bundle -I . d.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
d3:
	oj-bundle -I . d.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
d4:
	oj-bundle -I . d.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
e:
	oj-bundle -I . e.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a
e1:
	oj-bundle -I . e.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
e2:
	oj-bundle -I . e.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
e3:
	oj-bundle -I . e.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
e4:
	oj-bundle -I . e.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
f:
	oj-bundle -I . f.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a
f1:
	oj-bundle -I . f.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
f2:
	oj-bundle -I . f.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
f3:
	oj-bundle -I . f.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
f4:
	oj-bundle -I . f.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
g:
	oj-bundle -I . g.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a
g1:
	oj-bundle -I . g.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
g2:
	oj-bundle -I . g.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
g3:
	oj-bundle -I . g.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
g4:
	oj-bundle -I . g.cpp > submit.cpp
	g++ submit.cpp -std=gnu++20 -D _GLIBCXX_DEBUG -H -I . -o a
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt
r:
	./a
r1:
	./a < in1.txt
r2:
	./a < in1.txt
	./a < in2.txt
r3:
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
r4:
	./a < in1.txt
	./a < in2.txt
	./a < in3.txt
	./a < in4.txt

at:
	-rm -f *.exe
	rm -f a.cpp
	rm -f b.cpp
	rm -f c.cpp
	rm -f d.cpp
	rm -f e.cpp
	rm -f f.cpp
	rm -f g.cpp
	cp template.cpp a.cpp
	cp template.cpp b.cpp
	cp template.cpp c.cpp
	cp template.cpp d.cpp
	cp template.cpp e.cpp
	cp template.cpp f.cpp
	cp template.cpp g.cpp
	touch in1.txt
	touch in2.txt
	touch in3.txt
	touch in4.txt
