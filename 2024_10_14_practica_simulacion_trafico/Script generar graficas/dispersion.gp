 # Script de configuración para gnuplot que genera un diagrama de dispersión del promedio de tiempo de espera por hora.
 # El Script fue generado con asistencia de ChatGPT.
 #Para graficar se uso la pagina: https://gnuplot.io/
 
set title 'Promedio de Tiempo de Espera por Hora'
set xlabel 'Hora del Día'
set ylabel 'Tiempo de Espera Promedio (minutos)'
plot 'datos_dispersión.txt' using 1:2 with points pointtype 7 title 'Tiempo de Espera'