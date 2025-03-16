from bokeh.plotting import figure,show
from bokeh.models import ColumnDataSource,Label,LabelSet
from bokeh.io import output_file

x = [1,2,3,4,5]
y = [2,4,6,8,10]

p=figure(title = "line graph with Annotation and legends",x_axis_label = 'x-axis',y_axis_label = 'y-axis')

source = ColumnDataSource(data = {'x':x,'y':y})

p.line('x','y',source = source ,legend_label = 'line plot',line_color = 'blue',line_width = 2)

label = Label(
    x=3,y=6,
    x_units = 'data',y_units = 'data',
    text = 'Annotation',
    background_fill_color = 'lightgrey',
    background_fill_alpha = 0.7,
)

p.add_layout(label)

p.legend.title = 'Legend'
p.legend.label_text_font_size = '12pt'
p.legend.background_fill_alpha = 0.7

labels = LabelSet(
    x = 'x',y = 'y',
    text = 'y',
    level = 'glyph',
    source = source,
    text_baseline = 'middle',
    text_align = 'center',
    text_font_size = '12pt'
)

p.add_layout(labels)

output_file('line_graph_with_annotation_and_legends.html')

show(p)