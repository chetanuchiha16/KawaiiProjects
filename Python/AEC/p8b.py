from bokeh.plotting import figure,show,output_file
from math import pi
from bokeh.models import ColumnDataSource


x=[1,2,3,4,5]
y=[2,4,6,8,10]

output_file("bokeh_plot1.html")

p1 = figure(title = "line Plot",x_axis_label = 'x_axis',y_axis_label = 'y-axis')
p1.line(x,y,line_color='blue',line_width = 2)

p2 = figure(title = "scatter plot",x_axis_label = 'x_axis',y_axis_label = 'y_axis')
p2.scatter(x,y,size=20,color = 'green',alpha = 0.6)

Categories = ['Category A','Category B','Category C','Category D']
Values = [30,45,15,10]

p3 = figure(x_range = Categories,title = "Bar Plot",x_axis_label = 'Categories',y_axis_label = "Valures")
p3.vbar(x=Categories,top = Values, width = 0.5,color = 'orange')

angles = [pi/4,pi/2,pi,1.5*pi]
data = {
    'Categories':['Category A','Category B','Category C','Category D'],
  #  'Values':[30,45,15,10],
    'start_angle':angles,
    'end_angle':angles[1:]+[2*pi],
    'fill_color':['red','green','blue','orange']

}
p4 = figure(title = "Pie Chart")
source = ColumnDataSource(data)

p4.wedge(
    x=0,
    y=0,
    radius = 0.4,
    start_angle = 'start_angle',
    end_angle = 'end_angle',
    line_color = "white",
    fill_color = 'fill_color',
    legend_field = "Categories",
    source = source,

)

show(p1)
show(p2)
show(p3)
show(p4)