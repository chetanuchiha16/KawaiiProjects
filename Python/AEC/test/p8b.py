from bokeh.plotting import output_file, figure , show
from bokeh.models import ColumnDataSource
from math import pi


x=[1,2,3,4]
y = [2,4,6,8]

output_file("plot.html")

fig1 = figure(
    x_axis_label = "x-axis",
    y_axis_label = 'y-axis',
    
)

fig1.line(x=x,y=y,line_width = 10,line_color = 'blue')
show(fig1)

fig2 = figure(
    x_axis_label = "x-axis",
    y_axis_label = 'y-axis',
)

fig2.scatter(
    x,y,
    alpha = 0.6,
    size = 10,
    color = 'red'
)

show(fig2)

fig3 = figure(x_axis_label = "x-axis",y_axis_label = 'y-axis',title = 'bar')

fig3.vbar(x,top = y,color = 'blue',width = 0.5)
show(fig3)

angle = [pi/4,pi/2,pi,1.5*pi]
cat = ['c1','c2','c3','c4']
val = [20,40,50,60]
data = {
    'start_angle': angle,
    'end_angle': angle[1:]+[2*pi],
    'fill_color': ['blue','black','yellow','red'],
    'legend_field': cat,
    'value':val
}
source = ColumnDataSource(data)

fig4 = figure(title = 'Pie Chart')
fig4.wedge(
    x=0,y=0,
    radius = 0.4,
    
    start_angle = 'start_angle',
    end_angle = 'end_angle',
    fill_color = 'fill_color',
    legend_field = 'legend_field',
    source = source,
)
show(fig4)