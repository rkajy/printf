# =========================
# Variables de répertoires
# =========================
SRC_DIR     := src
TEST_DIR    := test
UNITY_DIR   := unity/src
BUILD_DIR   := build
OBJ_DIR     := $(BUILD_DIR)/objs
RESULTS_DIR := $(BUILD_DIR)/results
DEP_DIR     := $(BUILD_DIR)/depends

# =========================
# Fichiers sources
# =========================
SRC_FILES   := $(SRC_DIR)/ft_memset.c \
               $(SRC_DIR)/ft_printf.c \
               $(SRC_DIR)/parse_format.c \
               $(SRC_DIR)/printf_test.c \
               $(SRC_DIR)/test.c

TEST_FILES  := $(TEST_DIR)/Testft.c \
               $(TEST_DIR)/compare_printfs.c \
               $(TEST_DIR)/ft_vsnprintf.c

UNITY_FILES := $(UNITY_DIR)/unity.c

# =========================
# Tous les objets compilés
# =========================
OBJS        := $(SRC_FILES:%.c=$(OBJ_DIR)/%.o) \
               $(TEST_FILES:%.c=$(OBJ_DIR)/%.o) \
               $(UNITY_FILES:%.c=$(OBJ_DIR)/%.o)

# =========================
# Compilation & flags
# =========================
CC          := cc
CFLAGS      := -I. -I$(DEP_DIR) -I$(SRC_DIR) -I$(UNITY_DIR) -DTEST

# =========================
# Cible principale pour tester
# =========================
test: $(RESULTS_DIR)/Testft

$(RESULTS_DIR)/Testft: $(OBJS)
	@mkdir -p $(RESULTS_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# =========================
# Compilation des .o
# =========================
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Nettoyage
# =========================
clean:
	rm -rf $(OBJ_DIR) $(RESULTS_DIR) $(DEP_DIR) src/*.out

norminette:
	if ! command -v norminette &> /dev/null; then \
		python3 -m pip install --upgrade pip; \
		python3 -m pip install norminette; \
	fi
	norminette $(PATHS)

format_norm:
	if ! command -v c-formatter-42 &> /dev/null; then \
		pip3 install --user c_formatter_42; \
	fi
	bash utils/format_norm.sh

update_unity:
	git clone https://github.com/ThrowTheSwitch/Unity.git unity

install_paco:
	bash -c "$$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"

.PHONY: all compile test clean install norminette format_norm