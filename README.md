# Controle de Reservatorio de Água

***Autores:*** *[Rodrigo Hiury](https://www.github.com/rodrigohiury), [Igor Maia Sales](https://github.com/IgorMaiaSales), [Ludwig Bezerra Sales](https://github.com/Ludwigbsales), [Juan Porto](https://github.com/juannporto)*

Projeto para da matéria de Sistemas Microprocessados em 2021.2 da Universidade Federal do Ceará.
> [Vídeo de apresentação no Youtube](https://youtu.be/42zYZS4uKNc)

## Descrição

Este é um projeto para um sistema de controle de reservatório de água. Nosso sistema controla o nivel do reservatório baseada na pressão e temperatura da água, calculando automaticamente o nível atualmente ocupado no reservatório e ligando e desligando uma bomba para enchê-lo.
Nosso sistema foi projetado para reservatórios de água, mas podem ser usado outros líquidos e até mesmo gases, com pequenas modificações no código-fonte.
O sistema foi feito para reservatórios de pequeno a médio porte. Podendo ser utilizada em desde caixas d'água residenciais a reservatórios industriais de médio porte.
O sistema foi projetado usando o Microcontrolador **STM32F103C6**, da empresa ST_Link. O código-fonte foi construído em linguagem **C** no programa **STM32CubeIDE**, e o sistema, simulado usando o **Proteus 8.11 SP0 (Build 30052)**.

## Peças

Para as peças utilizadas no sistema, além do microcontrolador escolhido, foram utilizados:

> - [Sensor de Pressão MPX4115A](https://www.nxp.com/docs/en/data-sheet/MPX4115.pdf)
> - [Sensor de Temperatura LM35](https://www.ti.com/lit/ds/symlink/lm35.pdf)
> - [Visor LCD LM041L 16x4](https://datasheetspdf.com/pdf-file/573111/HitachiSemiconductor/LM041L/1)
> - 16 botões simples (Substituindo teclado matricial)

O Projeto foi feito em conjunto com os 4 membros, mas a implementação de cada peça descrita acima foi feita individualmente. Após a implementação feita, juntamos cada parte e montamos conjuntamente o sistema.

## Implementação

### Sensor de Pressão

- Ludwig Bezerra Sales

> *"Bom, fiquei responsável pela ligação e funcionamento do sensor de pressão utilizado, que foi o MPX4115, li o datasheet, vi como ligar os pinos e o fiz, porém, ao utilizar a > fórmula de saída do valor da pressão que o datasheet disponibiliza, apresentou uma divergência enorme em relação ao valor do visor do sensor, daí tiramos um tempo e o Rodrigo > veio com a solução, ele havia utilizado um site para elaborar um polinômio que corrigisse o valor da pressão apresentada.
> Após a correção da pressão, nos vimos diante de outro problema, a utilização do controlador ADC1 com dois sensores analógicos, Rodrigo novamente veio com a solução, ele havia > pesquisado e encontrado uma forma de utilizar os dois sensores no mesmo controlador, diferenciando canais e possibilitando a leitura de ambos (temperatura e pressão).
> Dito isso, as linhas de código utilizadas para o correto funcionamento do sensor são basicamente: definir duas variáveis (o valor lido pelo controlador ADC e a pressão, depois > da conversão), inicialização do controlador ADC, dar um delay para a leitura do valor, obter o valor “cru” (por isso o nome da variável: raw), o converter e por fim imprimir no visor."*

### Sensor de Temperatura

- Juan Porto

> *"Foi escolhido o sensor LM35, que é um sensor de temperatura que apresenta uma tensão linear proporcional a temperatura medida, devido ao fato do sensor não precisar ser calibrado, não houve grandes dificuldades em sua leitura, só foi necessário traduzir de binario para decimal. A ligação foi feita ligando o pino 1 ao Vcc, pino 3 ao GND e o pino 2 ao microcontrolador, também não houve dificuldades na montagem devido a simplicidade do sensor."*

### Visor LCD

- Rodrigo Hiury

> *"O Visor que escolhi foi um visor LCD de 16 colunas por 4 linhas. Escolhi esse visor por conta do maior espaço disponível para informações ao usuário.
> Para usá-lo no sistema, foi necessário a construção de funções para enviar comandos ao visor e mostrar as informações necessárias.
> Antes, é preciso iniciá-lo. Tive algumas dificuldades com a inicialização do LCD. Pois não há informações muito detalhadas sobre, nem é descrito pelo datasheet do LCD nem na lista de comandos como se faz a inicialização. Após algumas horas de pesquisa, tentativa e erro, consegui chegar a inicialização correta do LCD. A inicialização do visor consiste em configurar o modo com que as informações serão enviadas e escritas no visor.
> Primeiro configuramos o tamanho da letra no visor, depois configuramos o cursor, depois o modo de escrita da tela, depois limpamos a tela e setamos o cursor pra posição (0,0).
> No nosso caso, foi usado a configuração de 2 linhas, matriz 5x8. O cursor foi ocultado e o modo de escrita foi usado da esquerda pra direita, sem deslocamento.
> Após a inicialização, pude usar o visor normalmente.
> Para escrever no visor, temos que primeiro setar a posição do cursor, isto é, a posição que a letra ou o número mais a esquerda será escrito, e então enviar o dado a ser escritos de 8 em 8 bits ou de 4 em 4 bits. Foi escolhido para o projeto de 8 em 8 bits.
> Para o controlar o LCD, é relativamente simples. A Lista de comandos que o LM041L aceita está listado [neste site](https://mil.ufl.edu/3744/docs/lcdmanual/commands.html#Wr). Assim, é possível mandar comandos de enviar caracteres para o visor, limpá-lo ou mudar a posição do cursor como desejado. As funções de controle do LCD estão documentadas dentro do projeto."*

### Teclado Matricial

- Igor Maia Sales

> *"[Inserir texto sobre o teclado matricial]"*

### Montagem do Projeto

Após a conclusão das partes de todos, conseguimos construir nosso programa. Construimos 2 arquivos sources para o lcd e o sensor de pressão, respectivamente. Após incluído na main, começamos a funções. Como nosso projeto não possui teclado, consideramos um reservatório de 2mt de altura. Não é preciso considerar volume aqui. Então lemos a entrada do AD referente ao sensor de pressão, convertemos para kPa. Depois lemos a entrada do AD referente a temperatura do sensor e convertemos para ºC (Graus Celcius). Usamos a temperatura da água para calcular a densidade e calculamos a altura atual do reservatório com a pressão e a densidade. Então verificamos se essa altura é menor que 95% da capacidade do reservatório. Se for, enviamos um sinal elétrico para uma das portas do microcontrolador para ativar uma bomba de sucção e imprimimos uma mensagem no visor avisando que estamos ativando a bomba. Se a bomba estiver ligada e o nível chegar a 95%, desligamos a bomba e imprimimos um aviso no LCD. Por fim, imprimimos o nome reservatório e as informaões no visor. Ele irá repetir esse processo enquanto estiver ligado. Abaixo segue o esquema de pinagem que usamos no projeto.

![unknown](https://user-images.githubusercontent.com/36707294/154401291-dac87ccf-1c7c-44e3-bbcc-0d3e2146a9f7.png)

Como visto acima, também usamos 2 canais do ADC1, um para a pressão, outro para a temperatura. Para que conseguíssemos usar os dois canais, foi nescessário a implementação de 2 funções que iniciam o ADC1 no canal que queremos, lemos o valor do ADC1 no canal requerido e desativamos o canal novamente.

### Funcionamento

O Nosso sistema funciona da seguinte forma: O sensor de pressão é conectado ao fundo do reservatório juntamente com o sensor de temperatura. O sensor é conectado ao microcontrolador. Então conectamos o microcontrolador a uma bomba de sucção. Isso pode ser feito por meio de uma contatora simples. Após tudo conectado e ligado, iniciamos o sistema. O sistema irá calcular automaticamente o nível da água do reservatório baseado na pressão e temperatura da água no fundo, considerando um reservatório de 2 mt de altura.

### Dificuldades

Bem, como já foi descrito acima, enfrentamos alguns percalços na contrução do projeto. Primeiro o LCD, depois o sensor de pressão, por ultimo o teclado matricial. Tentamos incluir o teclado no nosso projeto, mas houveram muitas falhas que impossibilitaram a inclusão do teclado. Primeiro, somente 1 das portas ativavam, depois conseguimos ativar todas, mas o teclado não lida os botões apropriadamente. Depois, conseguimos fazer que lêsse os botões, mas só alguns, e depois de um tempo, os pinos que mandavam os sinais pras linhas do teclado paravam de alternar, e destravava se apertássemos o botão de dividir do SMALLCALC. Então desistimos de usar o SMALLCALC do Proteus e usamos Switches simples. Quase conseguimos concluir a construção do teclado, como pode ser visto nesse [segundo repositório](https://github.com/IgorMaiaSales/ControleDeReservatorioDeLiquido), mas o proteus começou a apresentar uma lentidão excessiva quando pressionado um botão, o que tornou inviável a inclusão deste no projeto.

### Conclusão

Apesar de todas as dificuldades, a contrução do sistema foi algo muito interessante e produtivo. Mexer nas funções do STM32, construir um dispositivo próprio, quebrar a cabeça com os problemas que apareciam tornaram o processo muito interessante. E, por isso, nos orgulhamos do que nós contruímos. Esperamos que você possa gostar do que fizemos, e qualquer dúvida ou sugestão, estamos a disposição.
