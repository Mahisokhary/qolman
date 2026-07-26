QOLMAN_OBJS := $(patsubst %,$(BUILD_DIR)/obj/%.o,$(call RESOLVE_SOURCES,qolman,.c))

$(BUILD_DIR)/libqolman.so: $(QOLMAN_OBJS)
	$(info > Linking $@)
	gcc $(GCC_FLAGS) --shared $(QOLMAN_OBJS) -o $@
BUILD_TARGETS += $(BUILD_DIR)/libqolman.so

