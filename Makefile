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

EXTENSIONS42 = \
	keyhr.42-c-format \
	mariusvanwijk-joppekoers.codanorminette-3 \
	kube.42header \
	dokca.42-ft-count-line \
	tomoki1207.pdf \
	GitHub.copilot \
	GitHub.copilot-chat \
	cschleiden.vscode-github-actions

# =========================
# Fichiers sources
# =========================
SRC_FILES   := $(SRC_DIR)/ft_printf.c \
			   $(SRC_DIR)/ft_parse_flags.c \
               $(SRC_DIR)/ft_print_arg.c \
			   $(SRC_DIR)/ft_print_utils_alphabet.c \
			   $(SRC_DIR)/ft_print_utils_numeric.c
# =========================

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


bonus:
	@$(MAKE) -C $(SRC_DIR) bonus

# =========================
# Cible principale pour tester
# =========================
test: $(RESULTS_DIR)/Testft
	@echo "==== Lancement des tests ===="
	@./$(RESULTS_DIR)/Testft > $(RESULTS_DIR)/test_output.txt || true
	@if grep -q FAIL $(RESULTS_DIR)/test_output.txt; then \
		echo "❌ Tests échoués"; \
		cat $(RESULTS_DIR)/test_output.txt; \
		exit 1; \
	fi
	@cat $(RESULTS_DIR)/test_output.txt
	@echo "==== Fin des tests ✅ ===="

test-valgrind: $(RESULTS_DIR)/Testft
	@echo "==== Lancement des tests avec Valgrind ===="
	@valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(RESULTS_DIR)/Testft \
		|| { echo "❌ Valgrind a détecté des fuites ou erreurs"; exit 1; }
	@echo "==== Fin des tests Valgrind ✅ ===="

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
	@$(MAKE) -C $(SRC_DIR) clean
	@$(MAKE) -C $(SRC_DIR) fclean

norminette:
	if ! command -v norminette &> /dev/null; then \
		python3 -m pip install --upgrade pip; \
		python3 -m pip install norminette; \
	fi
	norminette $(SRC_DIR)

format_norm: # work on linux only
	if ! command -v c-formatter-42 &> /dev/null; then \
		pip3 install --user c_formatter_42; \
	fi
	bash utils/format_norm.sh

install_unity:
	@echo "==== Mise à jour de Unity ===="
	rm -rf unity
	git submodule add https://github.com/ThrowTheSwitch/Unity.git unity


install-ohmyzsh:
	@echo "Vérification de zsh..."
	@if ! command -v zsh >/dev/null 2>&1; then \
		echo "zsh non trouvé, installation..."; \
		if [ "$$(uname)" = "Darwin" ]; then \
			brew install zsh; \
		else \
			sudo apt-get update && sudo apt-get install -y zsh; \
		fi \
	else \
		echo "zsh déjà installé"; \
	fi
	@echo "Vérification du shell par défaut..."
	@if [ "$$SHELL" != "$$(which zsh)" ]; then \
		echo "Changement du shell par défaut pour zsh..."; \
		chsh -s $$(which zsh); \
	else \
		echo "zsh est déjà le shell par défaut"; \
	fi
	@echo "Vérification de Oh My Zsh..."
	@if [ ! -d "$$HOME/.oh-my-zsh" ]; then \
		echo "Installation de Oh My Zsh..."; \
		if command -v curl >/dev/null 2>&1; then \
			sh -c "$$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"; \
		elif command -v wget >/dev/null 2>&1; then \
			sh -c "$$(wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"; \
		else \
			echo "Erreur : curl ou wget requis pour installer Oh My Zsh"; \
			exit 1; \
		fi \
	fi
	@echo "Installation des plugins Oh My Zsh..."
	@if [ ! -d "$$HOME/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting" ]; then \
		git clone https://github.com/zsh-users/zsh-syntax-highlighting.git $$HOME/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting; \
	fi
	@if [ ! -d "$$HOME/.oh-my-zsh/custom/plugins/zsh-autosuggestions" ]; then \
		git clone https://github.com/zsh-users/zsh-autosuggestions $$HOME/.oh-my-zsh/custom/plugins/zsh-autosuggestions; \
	fi
	@echo "Installation terminée. Redémarre ton terminal pour appliquer zsh par défaut."

install_valgrind:
	@echo "==== Installation de Valgrind ===="
	@unameOut=$$(uname); \
	if [ "$$unameOut" = "Darwin" ]; then \
		if ! command -v valgrind &> /dev/null; then \
			if ! command -v brew &> /dev/null; then \
				echo "Homebrew non trouvé, installation de Homebrew..."; \
				/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"; \
			fi; \
			brew install --HEAD valgrind || echo "Erreur : valgrind non disponible sur cette version de macOS"; \
		else \
			echo "Valgrind déjà installé"; \
		fi \
	elif [ "$$unameOut" = "Linux" ]; then \
		if ! command -v valgrind &> /dev/null; then \
			if command -v apt &> /dev/null; then \
				sudo apt update && sudo apt install -y valgrind; \
			elif command -v yum &> /dev/null; then \
				sudo yum install -y valgrind; \
			elif command -v pacman &> /dev/null; then \
				sudo pacman -Sy valgrind; \
			else \
				echo "Erreur : gestionnaire de packages non supporté"; \
			fi \
		else \
			echo "Valgrind déjà installé"; \
		fi \
	else \
		echo "OS non supporté pour l'installation automatique de Valgrind"; \
	fi

install_doxygen:
	@echo "==== Installation de Valgrind et Doxygen ===="
	sudo apt update
	sudo apt install -y doxygen graphviz
	@echo "==== Installation terminée ===="
	@doxygen --version

install42:
	@echo "🔧 Installation des extensions VSCode..."
	@for ext in $(EXTENSIONS42); do \
		code --install-extension $$ext || echo "⚠️  Erreur sur $$ext"; \
	done
	@echo "✅ Installation terminée."


.PHONY: all compile test test-valgrind clean install norminette format_norm install_unity install-ohmyzsh install_valgrind install_doxygen install42
