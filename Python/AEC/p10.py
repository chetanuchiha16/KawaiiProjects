import plotly.express as px
state_abbrev = ['NY', 'CA', 'IL', 'CA']
locname=['New York','Los Angeles','Chicago','San Francisco']


fig=px.scatter_geo(
    locations=state_abbrev,
    locationmode='USA-states',
    text=locname,
)


fig.update_geos(
    projection_scale=10,
    center = dict(lon=-95,lat = 38),
    visible=True,
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