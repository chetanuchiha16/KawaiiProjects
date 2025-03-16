import plotly.express as px

location = ['CA', 'TX', 'NY', 'FL']
locname = ['california', 'texas' ,'New York', 'Florida']

fig = px.scatter_geo(locations = location,locationmode = 'USA-states',text = locname)

fig.update_geos(
    projection_scale = 10,
    center = dict(lon = -95, lat = 38),
    visible  = False,
    showcoastlines = True,
    coastlinecolor = 'RebeccaPurple',
    showlakes = True,
    lakecolor = 'blue',
    showland = True,
    landcolor = 'lightgreen',
    showocean = True,
    oceancolor = 'skyblue',
)

fig.update_layout(
    title = "USA MAP",
)

fig.show()