import plotly.graph_objects as go
import numpy as np

x=np.linspace(-5,5,100)
y=np.linspace(-5,5,100)

#print(x,y)

X,Y = np.meshgrid(x,y)
#print(X,Y)

Z = np.sin(np.sqrt(X**2+Y**2))

fig = go.Figure(data = go.Surface(z=Z,x=x,y=y))

fig.update_layout(
    scene=dict(
        zaxis_title = "Z-axis",
        yaxis_title = "Y axis",
        xaxis_title = "X-axis",
    ),

    title = "3D surface Plot",
)
help(fig)
fig.show()