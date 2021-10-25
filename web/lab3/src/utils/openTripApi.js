
function fetchOpenTripRadius(apiKey, lon, lat, radius) {
    const lon_min = lon - radius / 111000;
    const lon_max = lon + radius / 111000;
    const lat_min = lat - radius / 111000;
    const lat_max = lat + radius / 111000;

    return fetch(`http://api.opentripmap.com/0.1/ru/places/bbox` +
        `?lon_min=${lon_min}` +
        `&lat_min=${lat_min}` +
        `&lon_max=${lon_max}` +
        `&lat_max=${lat_max}` +
        `&format=geojson` +
        `&apikey=${apiKey}`
    );
}

function fetchOpenTripPlace(xid) {
    return fetch(`http://api.opentripmap.com/0.1/ru/places/xid` +
        `?xid=${xid}`
    );
}

export const openTripApi = {
    fetchOpenTripRadius,
    fetchOpenTripPlace,
};
