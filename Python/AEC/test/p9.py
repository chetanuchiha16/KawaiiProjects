import plotly.graph_objects as go
import numpy as np

x=np.linspace(-5,5,100)
y=np.linspace(-5,5,100)
X,Y = np.meshgrid(x,y)

Z = np.sin(np.sqrt(X**2+Y**2))

fig = go.Figure(
    data = go.Surface(
        x=x,y=y,z=Z,
    )
)

fig.update_layout(
    scene = dict(
        xaxis_title = 'x-axis',
        yaxis_title = 'y-axix',
        zaxis_title = 'z-axis',
    ),
    title = "3D plot"
)

fig.show()