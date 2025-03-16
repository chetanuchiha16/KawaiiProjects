import plotly.express as px
location=['new york','Los Angeles','Chicago','San Francisco']
longitude=[-74.0060,-118.2437,-87.6298,-122.4194]
latitude = [40.7128,34.0522,41.8781,37.7749]

fig=px.scatter_geo(
    lat=latitude,
    lon=longitude,
    locationmode='USA-states',
    text=location,
)


fig.update_geos(
    projection_scale=10,
    center = dict(lon=-95,lat = 38),
    visible=False,
    showcoastlines=True,
    coastlinecolor='RebeccaPurple',
    showland= True,
    landcolor='LightGreen',
    showocean=True,
    oceancolor='LightBlue',
    showlakes=True,
    lakecolor="LightBlue", 
)   

fig.update_layout(
    title_text='Sample US Maps',
    title_x=0.5,
)

fig.show()


