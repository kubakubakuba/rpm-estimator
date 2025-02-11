OBJS = main.cc img.cc filter.cc process.cc regression.cc
LIBS = img.hh stb_image.h stb_image_write.h filter.hh fast_gaussian_blur.h process.hh regression.hh

CXX = g++
CFLAGS = -O2 -std=c++17
#EXTRA_CFLAGS ?= -DDEBUG
EXTRA_CFLAGS ?= -lpng
ZIP = estimator.zip

OUT_EXE = main

all: $(OUT_EXE)

$(OUT_EXE): $(OBJS) $(LIBS)
	$(CXX) $(CFLAGS) $(EXTRA_CFLAGS) -o $(OUT_EXE) $(OBJS)

%.o: %.cpp | %.cc
	$(CXX) $(CFLAGS) $(EXTRA_CFLAGS) -c -o $@ $<

run: all
	./$(OUT_EXE)

zip:
	zip $(ZIP) $(OBJS) $(LIBS) Makefile

clean:
	rm -f *.o $(OUT_EXE) $(ZIP)

git_%: clean
	git add .
	git commit -m "$*"
	git push
