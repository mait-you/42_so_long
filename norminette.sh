#!/bin/bash

# Colors for output
GREEN='\033[32m'
BLUE='\033[34m'
RED='\033[31m'
YELLOW='\033[33m'
CYAN='\033[36m'
BOLD='\033[1m'
GRAYL='\033[90m'
RESET='\033[0m'

print_header()
{
	echo -e "${CYAN}"
	echo    "╔══════════════════════════════════════════════════╗"
	echo    "║                🚀  Norminette  🚀                ║"
	echo -e "╚══════════════════════════════════════════════════╝${RESET}"
}

show_help()
{
    clear
    echo -e "$YELLOW Usage: ./norminette.sh [-i] [-h] $RESET"
    echo -e "$YELLOW Options: $RESET"
    echo -e "$CYAN  -i    Show info messages $RESET"
    echo -e "$CYAN  -h    Show this help message $RESET"
    exit 0
}

if [[ "$1" == "-h" ]] || [[ "$1" == "--help" ]]; then
    show_help
fi

main()
{
	clear
	print_header
	norminette | while read -r line; do
		if [[ $line == *"Error"* ]]; then
			echo -e "$RED $line $RESET"
			error_file=$(echo "$line" | awk '{print $1}')
			while read -r line; do
				if [[ $line != *"Error"* ]]; then
					break
				fi
				line_num=$(echo "$line" | awk '{printf "%d", $4}')
				col_num=$(echo "$line" | awk '{printf "%d", $6}')
				error_msg=$(echo "$line" | awk -F'\\):' '{print $2}' | sed 's/^ *//')
				echo -e "$GRAYL $BOLD $error_file$line_num:$col_num$error_msg $RESET"
			done
		else
			if [[ "$1" != "-i" ]]; then
				echo -e "$GREEN $line $RESET"
			fi
		fi
	done
}

main "$1"
