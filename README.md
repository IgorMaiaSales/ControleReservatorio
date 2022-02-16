# Controle de Reservatorio de Água

***Autores:*** *[Rodrigo Hiury](https://www.github.com/rodrigohiury), [Igor Maia Sales](https://github.com/IgorMaiaSales), [Ludwig Bezerra Sales](https://github.com/Ludwigbsales), Juan Porto*

Projeto para da matéria de Sistemas Microprocessados em 2021.2 da Universidade Federal do Ceará.

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
> - Teclado Matricial 4x4



[incluir texto sobre sensor de pressão]

[incluir texto sobre o sensor de temperatura]

O Visor escolhido foi um visor LCD de 16 colunas por 4 linhas. Esse visor foi escolhido por conta do maior espaço disponível para informações ao usuário.
Para usá-lo no sistema, foi nescessário a construção de funções para enviar comandos ao visor e mostrar as informações nescessárias.
Para usar o visor, é nescessário primeiro, iniciá-lo. A inicialização do visor consiste em configurar o modo com que as informações serão enviadas e escritas no visor.
Primeiro configuramos o tamanho da letra no visor, depois configuramos o cursor, depois o modo de escrita da tela, depois limpamos a tela e setamos o cursor pra posição (0,0).
No nosso caso, foi usado a configuração de 2 linhas, matriz 5x8. O cursor foi desligado e o modo de escrita foi usado da esquerda pra direita, sem deslocamento.
Após a inicialização, podemos usar o visor normalmente.
Para escrever no visor, temos que primeiro setar a posição do cursos, isto é, a posição que a letra ou o número mais a esquerda será escrito, e então enviar o dado a ser escrito.
