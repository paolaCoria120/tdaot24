# Este script configura un gráfico de mapa de calor y utiliza 
#una herramienta de gráficos externa como Gnuplot para visualizar los datos.
# El Script fue generado con asistencia de ChatGPT.
#Para graficar se uso la pagina: https://gnuplot.io/
 
set title 'Mapa de Calor de Densidad de Tráfico por Hora'
set xlabel 'Hora del Día'
set ylabel 'Índice'
set palette defined (0 "blue", 1 "green", 2 "yellow", 3 "red") # Define la paleta de colores

# Configurar el mapa de calor
set style data pm3d
set pm3d map
set grid
splot 'datos_calor.txt' using 1:2:3 with pm3d title 'Densidad de Tráfico'