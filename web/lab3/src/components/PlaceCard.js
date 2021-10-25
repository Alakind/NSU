
function PlaceCard({ place }) {
    return (
        <div>
            <h3>{place.name}</h3>
            <div>{place.wikipedia_extracts?.text}</div>
        </div>
    );
}

export { PlaceCard };
