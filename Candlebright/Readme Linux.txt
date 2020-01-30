Instruções para executar o Candlebright: Ominous Whip.

Para executar o jogo no Linux basta rodar o comando:
'LD_LIBRARY_PATH=sfml/lib ./bin/jogo'.



Instruções para compilação Candlebright: Ominous Whip.

Este jogo pode ser compilado utilizando o Makefile com o comando 'make'.
O arquivo irá gerar todas as pastas e baixará as dependências (SFML, no caso).

Para executar, pode-se utilizar o comando 'make execute', o qual será responsável
por configurar as variáveis de ambiente para a execução do jogo.

Observação: este Makefile foi testado utilizando o GNU Make 4.2.1. Caso haja algum problema
durante a compilação do jogo, pode-se utilizar o comando 'make compile-older'.

Observação: a execução do jogo utilizando o Makefile foi testada apenas em Linux.


Makefile construído em colaboração com Heitor Tonel Ventura (2086883).
