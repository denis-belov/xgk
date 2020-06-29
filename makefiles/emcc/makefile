DIR=E:/reps/denis-belov/xgk__
SRC=$(DIR)/src
BUILD=$(DIR)/build-wasm
COMP_ARGS=-c



$(BUILD)/a/xgk.a : \
$(BUILD)/o/vec4.o
  emcc \
  $(BUILD)/o/vec4.o \
  -o $(BUILD)/a/xgk.a \
  --disable-shared



$(BUILD)/o/vec4.o : $(SRC)/data/vec4/vec4.cpp
  emcc \
  $(SRC)/data/vec4/vec4.cpp \
  $(COMP_ARGS) \
  -o $(BUILD)/o/vec4.o
