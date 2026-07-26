QOLMAN_INSTALL_HEADERS = $(call INSTALL_HEADER_RESOLVER,qolman)

$(INSTALL_DIR)/usr/lib/libqolman.so: $(BUILD_DIR)/libqolman.so
	$(info > Installing $@)
	install -Dm755 $< $@

INSTALL_TARGETS += \
		$(INSTALL_DIR)/usr/lib/libqolman.so \
		$(call INSTALL_HEADER_TO_TARGET,qolman,$(QOLMAN_INSTALL_HEADERS))

