Para realizar um 'build' deste projeto, é suficiente colocar todos os arquivos na mesma pasta para a
compilação e 'linkagem'.

Para a execução do programa com os testes, deve-se colocar o arquivo in.txt na mesma pasta que o 
executável produzido no 'build'.

Utilizando esse arquivo obtem-se como saída exatamente o esperado:
Linha  Coluna     Token     Tipo
    0     1            == : EQ
    1    -1            \n : NEWLINE
    2    -1            \n : NEWLINE
    2     0          1234 : NUM
    2     5         12314 : NUM
    2    10       a123124 : ID
    2    17       .546456 : NUM
    2    25     000000000 : NUM
    3    -1            \n : NEWLINE
    3     0           sss : ID
    4    -1            \n : NEWLINE
    5     0             + : PLUS
    6    -1            \n : NEWLINE
    6     0             = : ATTR
    7    -1            \n : NEWLINE
    7     0             - : MINUS
    7     2             _ : ERRO
    8    -1            \n : NEWLINE
    8     0            >= : GTE
    9    -1            \n : NEWLINE
    9     0            == : EQ
   10    -1            \n : NEWLINE
   10     0            <= : LTE
   11    -1            \n : NEWLINE
   11     5            != : NEQ