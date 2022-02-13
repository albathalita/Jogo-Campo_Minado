# Jogo - Campo Minado

Esse jogo foi feito com o conteúdo da disciplina de Linguagem de Programação da Universidade Federal do Rio Grande do Norte (UFRN), ministrada pelos professores Einstein Gomes dos Santos e Sérgio Queiroz de Medeiros.

### 1. Introdução

Este jogo é um jogo de computador bastante conhecido cujo objetivo é descobrir quadrados em um campo de minas sem detonar as minas. O jogo começa com uma tela inicial apresentando um campo/grade de quadrados iguais. Alguns desses quadrados possuem minas que são escolhidas aleatoriamente.

![alt text](https://github.com/albathalita/Jogo-Campo_Minado/blob/main/campo_minado-1.jpg)

Após aparecer a configuração inicial, o jogador, que não sabe em quais locais as minas estão, deve tentar descobrir ou até mesmo marcar onde as minas estão. Ao escolher um quadrado, o programa mostrará se tem ou não uma mina, caso tenha a mina o jogador perde, mas se não houver mina, mostrará um número contendo a quantidade de minas ou um quadrado em branco juntamente com seus adjacentes que não possuem minas são mostrados. A imagem abaixo mostra quando um jogador acerta em um quadrado em branco e em seguida temos uma imagem ilustrando quando o jogador acerta a mina.

![alt text](https://github.com/albathalita/Jogo-Campo_Minado/blob/main/campo_minado-2.png)
![alt text](https://github.com/albathalita/Jogo-Campo_Minado/blob/main/campo_minado-3.png)


### 2. Desenvolvimento

Esse jogo foi desenvolvido para que o usuário possa jogar o jogo tradicional podendo fazer marcações de onde sabe onde  está a mina e de onde tem dúvida do local da mina. O jogo também foi configurado para acabar quando o jogador perde ou quando todos os quadrados sem a mina são selecionados. E por fim, nele há 3 níveis de dificuldade, o Iniciante, com um campo de 8x8 e 10 minas, o Intermediário, com o campo de 16x16 com 40 minas, e o Personalizado, que o usuário pode escolher a dimensão respeitando o valor máximo de 40 e também escolhe o número de minas respeitando o número mínimo de `(altura x largura) - 10`.

### 3. Conclusão

Essa atividade ajuda na compreensão do assunto mininstrado em aula, pois há uma dificuldade em desenvolver esse jogo, como na execução da função recursiva e na manipulação de arquivos.
