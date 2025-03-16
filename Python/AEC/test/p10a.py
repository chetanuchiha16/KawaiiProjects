import plotly.graph_objects as go
import pandas as pd

data = {
    'date':pd.date_range(start = '01-01-2023',periods = 30,freq = 'D'),
    'value':[
        1,2,3,4,5,6,7,8,9,10,
        11,12,13,14,15,16,17,18,19,20,
        21,22,23,24,25,26,27,28,29,30,
    ]
}

df = pd.DataFrame(data)

fig=go.Figure(
    data = go.Scatter(
        x = df['date'],
        y = df['value'],
        mode = 'lines+markers',
        name = 'TIme Series'
    )
)

fig.update_layout(xaxis_title = 'date',yaxis_title = 'value',title = 'time series plot')

fig.show()