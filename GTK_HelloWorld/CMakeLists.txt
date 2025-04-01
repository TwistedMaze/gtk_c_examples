# Define a versão mínima necessária do CMake para o projeto.
cmake_minimum_required(VERSION 3.10)

#Set project name and version
project(HelloWorldGTK VERSION 1.0)


# Passo 1: Encontrar as bibliotecas GTK necessárias usando a ferramenta PkgConfig.
find_package(PkgConfig REQUIRED) # Garante que o PkgConfig está disponível.
pkg_check_modules(GTK REQUIRED gtk4) # Encontra a biblioteca GTK 4 (necessária para o projeto).

# Passo 2: Incluir os cabeçalhos do GTK no projeto.
# Adiciona os diretórios de cabeçalhos do GTK ao projeto.
include_directories(${GTK_INCLUDE_DIRS})

# Passo 3: Adicionar flags do compilador específicas do GTK.
add_definitions(${GTK_CFLAGS_OTHER})

# Passo 4: Criar o executável principal a partir do ficheiro de código-fonte.
# Cria o executável "helloworld" a partir do ficheiro "main.c".
add_executable(helloworld main.c)



# Passo 5: Ligar as bibliotecas GTK ao executável.
target_link_libraries(helloworld ${GTK_LIBRARIES})# Liga as bibliotecas GTK necessárias ao executável.