# Script de configuración para gnuplot que genera un diagrama de caja y bigotes
#del tiempo de espera por hora.
# El Script fue generado con asistencia de ChatGPT.
#Para graficar se uso la pagina: https://gnuplot.io/
 
set title 'Diagrama de Caja y Bigotes del Tiempo de Espera por Hora'
set xlabel 'Hora del Día'
set ylabel 'Tiempo de Espera (minutos)'
set style data boxplot
set style boxplot outliers pointtype 7
set style fill solid 0.5
set grid ytics
# Leer los datos separados por bloques para cada hora
plot for [i=0:23] 'datos_bigotes.txt' index i using (i):1 title sprintf('Hora %d', i)