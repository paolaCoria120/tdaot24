 # Script de configuración para gnuplot que genera un histograma de la distribución de autos por hora,
 # utilizando un archivo de datos llamado "datos_trafico.csv". Se genera un histograma con barras sólidas que 
 # representa el número de autos que llegan en cada hora del día.
 # El Script fue generado con asistencia de ChatGPT
 #Para graficar se uso la pagina: https://gnuplot.io/

set title 'Distribución de Autos por Hora'
set xlabel 'Hora del Día'
set ylabel 'Número de Autos'
set style fill solid
binwidth = 1
bin(x,width) = width*floor(x/width) + width/2.0
plot 'datos_trafico.csv' using (bin($1,binwidth)):(1.0) smooth freq with boxes title 'Autos'