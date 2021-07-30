# ProjetoFinal

Universidade Federal de Itajubá
UNIFEI



Relatório Técnico de Desenvolvimento do 
Projeto Final

Programação Embarcada



Maria Clara M. Santana
Turma 1
Matrícula: 2020012227
Prof.: Otávio Martins




Resumo

Este documento tem por objetivo relatar o processo de desenvolvimento do Projeto Final das matérias Programação Embarcada e Laboratório de Programação Embarcada, ambas contendo o mesmo projeto. Estão relatados o processo de criação da ideia, como foi realizado e produzido, as dificuldades e suas soluções, além da explicação do funcionamento. Todos esses itens referem-se ao Projeto da Cadeira de Rodas Automática produzido no MPLab X IDE, foi utilizado o XC8 e o PICSimLab com a placa PICGenios e PIC18F4520.




1 Introdução

 Foi proposto para os alunos de Programação Embarcada da UNIFEI o desenvolvimento de um projeto referente a toda a matéria que estudávamos no semestre. Isso inclui a produção
de um código do MPLab X IDE e sua execução no PICSimLab podendo ser executadas as funções dos LEDs, display LCD, displays de 7-seg, teclas, conversores analógicosdigitais, saídas de PWM e interrupção. 

  Para o desenvolvimento do projeto foi necessário a criação da ideia de qualquer coisa que pudesse ser representada no PICSimLab. Isto abrange diversas possibilidades, sendo possível ser bem criativo na criação da ideia.

  Foi preciso que o tema e um breve texto de explicação do funcionamento da ideia fosse enviada para o professor e colegas antes do contato com todas as funcionalidades disponíveis. Tendo em vista primeiro o desenvolvimento da ideia e apenas depois a preocupação de como produzi-la. Também com o objetivo de organização para evitar que mais de um aluno envie um tema muito semelhante ao de um colega.

Também foi produzido um vídeo da explicação do código e o funcionamento no PICSimLab para um maior controle de cópias entre projetos. Além de um maior esclarecimento sobre  todo o trabalho executado.



2 Desenvolvimento

  1 - Criação da Ideia da Cadeira de Rodas Automática

  A ideia foi elaborada com o auxílio da visualização de exemplos de projetos anteriores fornecidos pelo professor. Dessa forma, foi possível saber o que poderia ser utilizado entre LEDs, display LCD, displays de 7-seg, teclas, conversores analógicos digitais, saídas de PWM e interrupção.

O caminho para  a ideia foi iniciado com a semelhança do cooler com uma roda. Tendo isto em mente foi pensado em várias opções que contêm rodas no funcionamento, como um carro. Entretanto, os carros possuem inúmeras funcionalidades difíceis de serem reproduzidas apenas com o que tínhamos disponíveis e ainda deixar semelhante com a realidade.

Portanto, foi considerado veículos mais simples do que carros. Assim veio a ideia de uma cadeira de rodas. Porém, uma cadeira de rodas simples não utiliza as funcionalidades que podem ser representadas no PICSimLab.

Dessa forma, a ideia de uma cadeira de rodas automática que possuísse várias ferramentas para o funcionamento foi gerada.

A partir de uma ideia inicial, foram sendo incrementadas todas as funcionalidades que o projeto poderia ter.  Os seis dispositivos são:

1 - Cooler (Ventoinha).
2 - Teclado.
3 - Display de LCD. 
4 - LEDs. 
5 - Display de 7-Seg.
6 - Relé.

O cooler será a representação da roda.

O teclado será utilizado para a interação do controlador com a máquina. Assim será possível receber da pessoa o comando que ela quer que seja realizado.

O Display de LCD também contribui na interação homem-máquina. Nele serão exibidos os textos da máquina para o homem, fornecendo as opções que ele possui e o que está sendo realizado.

Os LEDs serão utilizados como uma representação visual do comando sendo obedecido. 

O display de 7-Seg representará a quantidade de bateria que a cadeira possui para deixar o utilizador ciente de quando precisa ser recarregada. 

O relé1 mostrará toda a vez que um movimento for executado.


 
	
  2 - Criação, dificuldades e soluções

  Para fornecer os documentos produzidos nesse projeto era necessário postar no GitHub tanto o código quanto este relatório. Contudo, a aluna que produziu este projeto não estava familiarizada com o ambiente GitHub e não sabia como fornecer o código e o relatório.

  Então, para resolver este problema inicial, a aluna foi em uma das aulas de Laboratório de Programação Embarcada no qual o professor da matéria tira algumas dúvidas. Lá foi explicado como criar uma conta e onde devem ser postados tanto o código quanto o material aqui produzido.

  Dessa forma, foi possível focar no desenvolvimento do código.

  O projeto foi iniciado na semana anterior a apresentação da biblioteca keypad, porém como já tinha sido realizado um exercício que era utilizado o PORTD para captar o pressionamento das teclas, foi achado que seria possível começar a realizar a produção do código.

Entretanto, um problema aparece quando não foi possível utilizar o PORTD para o teclado e para os LEDs ao mesmo tempo.  Porém, na semana seguinte foi apresentada a biblioteca keypad que tornou possível a captação das teclas sem o PORTD explicitamente. 

Contudo, os LEDs ainda não funcionam da forma como deveriam. Tendo em vista que o funcionamento do teclado precisa da utilização do PORTD, assim como os LEDs. Dessa forma, não estava sendo possível utilizar tanto o teclado como os LEDs da forma prevista.



Para resolver o problema foi preciso ter uma reunião com o professor no horário da disciplina de Laboratório de Programação Embarcada. Lá foi dito que era possível utilizar o PORTB para a representação dos LEDs. Entretanto, metade das luzes da coluna do PORTB eram de entrada, apenas a outra metade era de saída.

Para esse projeto desenvolvido, somente a metade da coluna de LEDs do PORTB era suficiente. Dessa forma, foi possível dar seguimento ao projeto.

  Outro problema que inicialmente foi encontrado foi a utilização do display de LCD apenas com as aulas iniciais de exibição na tela. Estava sendo complicado manusear os textos. Mas na semana seguinte da apresentação da biblioteca keypad foi apresentada a biblioteca LCD, tornando mais fácil a exibição do texto que deveria ser mostrado, no tempo correto, tornando possível a realização do que era para ser feito.

  O próximo passo a ser desenvolvido era a utilização do cooler. Um exemplo de utilização foi mostrado durante a aula. Assim, o desenvolvimento dessa parte do projeto foi facilitada. Dessa forma, o cooler foi um dos últimos componentes que foram planejados para serem utilizados a entrar em funcionamento, mas sem muitas  dificuldades.

Entretanto, foi notado que com o funcionamento do cooler, o relé1 também começou a acender, tornando possível a entrada de mais um componente no projeto.




  3 - Funcionamento

  Para o funcionamento da Cadeira de Rodas Automática, o usuário precisa primeiramente ligar a máquina.

Após ligada, irá aparecer no display de LCD quais teclas precisam ser pressionadas para realizar cada direção.  
	
Depois de selecionada a direção, aparece na tela qual o movimento está sendo executado.

Para finalizar o movimento é necessário pressionar novamente o mesmo botão. Ou seja, aperta uma vez para iniciar e aperta outra para terminar.

Depois de concluído, aparecem novamente na tela qual a opção de direção desejada.


Os LEDs irão acender de formas diferentes em cada movimento para mostrar visualmente qual direção está sendo tomada. Estando disponíveis 4 LEDs do PORTB, as seguintes luzes
acenderão para o respectivo movimento:

FRENTE:
*
o
o
o

TRÁS:
o
o
o
*

DIREITA:
*
*
o
o

ESQUERDA:
o
o
*
*

Legenda: (*) - Aceso. (o) - Apagado.


Já o cooler irá girar toda a vez que uma opção de movimento for selecionada para representar o funcionamento da roda. Caso nenhuma opção for selecionada, ele permanece em repouso.

O display de 7-Seg apresentará a quantidade de bateria que a cadeira possui. Começando do 100% indo até o 0%. Entretanto, caso chegue a zero, a cadeira para de funcionar. Logo, não se pode deixar isso acontecer.

Para tanto, é necessário recarregá-la. Isso será representado com o pressionamento de uma tecla. Ao apertar um botão, a cadeira automática terá sua bateria recarregada.

O relé1 irá acender toda a vez que uma tecla indicando um movimento for pressionada.

Agora serão apresentadas as funcionalidades de cada tecla que será utilizada:


TECLA (*) - Liga / Desliga 

TECLA (1) - Frente

TECLA (2) - Trás

TECLA (4) - Esquerda

TECLA (5) - Direita

TECLA (0) - Recarregar
	


Teclado

1	  2	  3

4	  5 	6

7	  8 	9

* 	0	  #



(Não foi necessária a utilização de todas as teclas.) 



  3 - Conclusão

	
   Nota-se que foram utilizadas 5 funcionalidades disponíveis do PICSimLab, escolhidas para se assemelhar com o funcionamento real que a cadeira de rodas automática precisaria 
  ter.

   Com este relatório também foi possível acompanhar um pouco da trajetória de como foi o desenvolvimento, dificuldades e soluções. Além de explicar qual a ideia e como ela 
 irá funcionar.

   Ao final do projeto, é possível concluir que a aluna que desenvolveu o trabalho aprendeu os conceitos ensinados na matéria e apresentados semanalmente e por fim 
 neste  projeto.

	
	





