from bokeh.plotting import figure, show, output_file
from bokeh.models import ColumnDataSource, Label,LabelSet
 

p1 = figure(x_axis_label = 'x-axis',y_axis_label = 'y-axis',title = 'line plot with annotation')
x = [1,2,3,4]
y = [2,4,6,8]
source = ColumnDataSource({'x':x,'y':y})

p1.line('x','y',source = source,legend_label = "line plot",line_width = 2,line_color = 'blue')

label = Label(
    x=3,y=6,
    background_fill_color = 'grey',
    x_units = 'data',y_units = 'data',
    text = 'Annotation',
    background_fill_alpha = 0.6,
)

p1.add_layout(label)

p1.legend.title = 'legend'
p1.legend.label_text_font_size = '12pt'
p1.legend.background_fill_alpha = 0.6

labels = LabelSet(
    x='x', y = 'y',
    text = 'y',
    text_align = 'center',
    text_baseline = 'middle',   
    source = source,
    #level = 'glyph',
)
output_file('plot_1.html')
p1.add_layout(labels)
show(p1)