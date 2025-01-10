#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 1 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Redirigir un archivo vacío y contar palabras (entrada vacía)"

./pipex emptyfile "cat" "wc -w" outfile_c_1
cat < emptyfile | wc -w > outfile_bash_1
#code outfile_c_1 outfile_bash_1

# Compare outputs
if diff -q "outfile_c_1" "outfile_bash_1" >/dev/null; then
	echo -e "${GREEN}Test 1:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 1: 🛑 NOT OK${RESET}"
fi

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 1 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 2 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Número incorrecto de argumentos (falta un argumento)"

echo "hola \na1 \na1 \na2" > infile
./pipex infile "ls -l" outfile_c_2


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 2 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 3 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: El archivo de entrada infile está vacío."

rm infile
touch infile
./pipex infile "cat" "wc -l" outfile_c_3
cat < infile | wc -l > outfile_bash_3
#code outfile_c_3 outfile_bash_3

# Compare outputs
if diff -q "outfile_c_3" "outfile_bash_3" >/dev/null; then
	echo -e "${GREEN}Test 3:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 3: 🛑 NOT OK${RESET}"
fi


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 3 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 4 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Archivo de entrada sin permisos de lectura."

rm infile
touch infile
chmod -r infile
./pipex infile "ls -l" "wc -l" outfile_c_4
ls -l < infile | wc -l > outfile_bash_4
#code outfile_c_4 outfile_bash_4

# Compare outputs
if diff -q "outfile_c_4" "outfile_bash_4" >/dev/null; then
	echo -e "${GREEN}Test 4:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 4: 🛑 NOT OK${RESET}"
fi


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 4 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 5 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Archivo de salida no accesible (directorio no existente)."

chmod +r infile
./pipex infile "ls -l" "wc -l" nonexistent_dir/outfile_c_5
ls -l < infile | wc -l > nonexistent_dir/outfile_bash_5


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 5 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 6 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Espacios en los comandos (sin comillas)"

./pipex infile ls -l wc -l outfile_c_6

#Bash: (No tiene equivalente exacto en Bash.)

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 6 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 7 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Interacción con grandes volúmenes de datos"

yes | head -n 10000 > largefile
./pipex largefile "cat" "wc -l" outfile_c_7
cat < largefile | wc -l > outfile_bash_7
#code outfile_c_7 outfile_bash_7

# Compare outputs
if diff -q "outfile_c_7" "outfile_bash_7" >/dev/null; then
	echo -e "${GREEN}Test 7:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 7: 🛑 NOT OK${RESET}"
fi

echo "removing largefile..."
rm largefile

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 7 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 8 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Archivos no especificados (sin infile y outfile)"

./pipex "" "ls -l" "wc -l" ""

#Bash: (No tiene equivalente exacto en Bash.)


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 8 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 9 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Concatenar el contenido de un archivo y buscar un patrón"

echo "hola\na1\na1\na2" > infile
./pipex infile "cat" "grep hola" outfile_c_9
cat < infile | grep "hola" > outfile_bash_9
#code outfile_c_9 outfile_bash_9

# Compare outputs
if diff -q "outfile_c_9" "outfile_bash_9" >/dev/null; then
	echo -e "${GREEN}Test 9:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 9: 🛑 NOT OK${RESET}"
fi


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 9 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 10 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Listar archivos y ordenar alfabéticamente"

#si no añadimos los outfile antes del test no se contaran bien los n de arch y dir:
if [ -f infile ]; then
    # Si es verdadero, ejecutar alguna acción
    touch infile
else
    # Si no es verdadero (el archivo no existe o no es un archivo regular)
    false
fi
# comandos:
ls -1 < infile | sort > outfile_bash_10
./pipex infile "ls -1" "sort" outfile_c_10
code outfile_c_10 outfile_bash_10

# Compare outputs
if diff -q "outfile_c_10" "outfile_bash_10" >/dev/null; then
	echo -e "${GREEN}Test 10:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 10: 🛑 NOT OK${RESET}"
fi


echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 10 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── Test 11 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo "Description: Concatenar el contenido de un archivo y buscar un patrón"


./pipex infile "echo 'Hello | World'" "wc -w" outfile_c_11
echo 'Hello | World' < infile | wc -w > outfile_bash_11
#code outfile_c_11 outfile_bash_11

# Compare outputs
if diff -q "outfile_c_11" "outfile_bash_11" >/dev/null; then
	echo -e "${GREEN}Test 11:✅ OK ${RESET}"
else
	echo -e "${RED}Tests 11: 🛑 NOT OK${RESET}"
fi

echo "✾❀──────✿❀❁✿──────❀✾•❀──────✿❀❁✿── End of Test 11 ──✿❀❁✿──────❀✾•❀──────✿❀❁✿─────✾❀"
echo ""








