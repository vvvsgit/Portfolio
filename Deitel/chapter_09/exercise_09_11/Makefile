progname=a.out
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -I. -std=c++03
debug:   CXXFLAGS+=-g3
release: CXXFLAGS+=-g0 -DNDEBUG

BUILD_DIR=builds
#debug:   BUILD_DIR+=/debug
#release: BUILD_DIR+=/release

HEADER_DIR=headers
SOURCE_DIR=sources
TEST_DIR=tests

TEST_INPUTS:=$(wildcard $(TEST_DIR)/test*.input)
SOURCES:=main.cpp $(wildcard $(SOURCE_DIR)/*.cpp)
DEPENDS:=$(patsubst %.cpp,$(BUILD_DIR)/%.d,$(SOURCES))
PREPROCS:=$(patsubst %.cpp,$(BUILD_DIR)/%.ii,$(SOURCES))
ASSEMBLES:=$(patsubst %.cpp,$(BUILD_DIR)/%.s,$(SOURCES))
OBJS:=$(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TESTS:=$(patsubst $(TEST_DIR)/%.input,%,$(TEST_INPUTS))

debug: $(BUILD_DIR) $(TESTS)
release: $(BUILD_DIR) $(BUILD_DIR)/$(progname)

test%: $(BUILD_DIR)/$(progname)
	./$< < $(TEST_DIR)/$@.input > $(BUILD_DIR)/$(TEST_DIR)/$@.output || echo "Negative test..."
	diff $(BUILD_DIR)/$(TEST_DIR)/$@.output $(TEST_DIR)/$@.expected > /dev/null && echo PASSED || echo FAILED

$(BUILD_DIR)/$(progname): $(OBJS) | .gitignore
	$(CXX) $(CXXFLAGS)    $^ -o $@

%.o: %.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.s: %.ii
	$(CXX) $(CXXFLAGS) -S $< -o $@

$(BUILD_DIR)/%.ii: %.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@
	$(CXX) $(CXXFLAGS) -MT $@ -MM $< > $(patsubst %.ii,%.d, $@)

.gitignore:
	echo $(progname) > .gitignore

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/$(SOURCE_DIR) $(BUILD_DIR)/$(TEST_DIR)

clean:
	rm -rf $(BUILD_DIR) $(progname) .gitignore

.PRECIOUS: $(PREPROCS) $(ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES)

sinclude $(DEPENDS)

