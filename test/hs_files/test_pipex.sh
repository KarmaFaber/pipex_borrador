#!/bin/bash

COMMANDS_FILE="test/commands.txt"
OUTPUT_DIR="$(pwd)/test/test_outputs"
INFILE="$(pwd)/infile"  # Ruta absoluta al infile

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# Function to print test headers
print_header() {
    echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿──Test $1──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
}

# Create test outputs directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Read commands file
while IFS= read -r line; do
    if [[ $line =~ ^[0-9]+\. ]]; then
        # Extract test number and description
        TEST_NUMBER=$(echo "$line" | cut -d. -f1)
        DESCRIPTION=$(echo "$line" | cut -d' ' -f2-)

        # Prepare test-specific paths
        TEST_DIR="$OUTPUT_DIR/test_$TEST_NUMBER"
        mkdir -p "$TEST_DIR"

        TEST_INFILE="$TEST_DIR/infile"
        OUTFILE_C="$TEST_DIR/outfile_c"
        OUTFILE_BASH="$TEST_DIR/outfile_bash"

        # Add content to the infile
        if [[ $TEST_NUMBER -eq 1 ]]; then
            echo -e "hola \n a1 \n a1" > "$TEST_INFILE"
        else
            echo -e "hola \n a1" >> "$TEST_INFILE"
        fi

        # Get the commands for C and Bash
        COMMAND_C=$(sed -n "/^$TEST_NUMBER\./{n;p;}" "$COMMANDS_FILE" | sed 's/^C:\s*//')
        COMMAND_BASH=$(sed -n "/^$TEST_NUMBER\./{n;n;p;}" "$COMMANDS_FILE" | sed 's/^bash:\s*//')

        # Replace placeholders with absolute paths
        COMMAND_C=${COMMAND_C//infile/$TEST_INFILE}
        COMMAND_C=${COMMAND_C//outfile/$OUTFILE_C}

        COMMAND_BASH=${COMMAND_BASH//infile/$TEST_INFILE}
        COMMAND_BASH=${COMMAND_BASH//outfile/$OUTFILE_BASH}

        # Execute the commands
        print_header "$TEST_NUMBER"
        echo "Description: $DESCRIPTION"
#        echo "Running C command: $COMMAND_C"
        eval "$COMMAND_C" >/dev/null 2>&1

#        @echo "Running Bash command: $COMMAND_BASH"
        eval "$COMMAND_BASH" >/dev/null 2>&1

        # Compare outputs
        if diff -q "$OUTFILE_C" "$OUTFILE_BASH" >/dev/null; then
            echo -e "${GREEN}Test $TEST_NUMBER:✅ OK ${RESET}"
        else
            echo -e "${RED}Tests $TEST_NUMBER: 🛑 NOT OK${RESET}"
        fi
        echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test $TEST_NUMBER ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
        echo ""
    fi
done < "$COMMANDS_FILE"