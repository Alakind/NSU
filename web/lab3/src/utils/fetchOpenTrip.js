
function fetchOpenTripRadius({ apiKey, lon, lat, radius }) {
    const lon_min = lon - radius;
    const lon_max = lon + radius;
    const lat_min = lat - radius;
    const lat_max = lat + radius;

    return fetch(` http://api.opentripmap.com/0.1/ru/places/bbox
        ?lon_min=${lon_min}
        &lat_min=${lat_min}
        &lon_max=${lon_max}
        &lat_max=${lat_max}
        &format=geojson
        &apikey=${apiKey}`
    );
}

export const fetchOpenTrip = {
    fetchOpenTripRadius,
};
