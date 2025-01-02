#!/bin/bash

# Definir colores para mensajes
RED='\033[1;31m'
GREEN='\033[1;32m'
RESET='\033[0m'

# Mensaje de advertencia
echo -e "${RED}⚠️  Warning: Are you sure you want to delete all test stats? (y/n)${RESET}"
read -r confirm

# Comprobar si el usuario confirmó
if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
    echo -e "${GREEN}Deleting test stats...${RESET}"

    # Eliminar archivos y directorios generados por los tests
    rm -rf test/test_outputs/single_test
    rm -rf test/test_outputs/multiple_tests_100
    rm -rf test/test_outputs/multiple_tests_500
    rm -rf test/test_outputs/test_valgrind_outputs

    # Confirmación de la eliminación
    echo -e "${GREEN}All test stats have been deleted successfully.${RESET}"
else
    echo -e "${RED}Operation cancelled. No files were deleted.${RESET}"
fi
