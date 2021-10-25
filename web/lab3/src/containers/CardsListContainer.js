import { PlaceCardContainer } from "./PlaceCardContainer";

function CardsListContainer({ places, maxShown }) {
    return (
        <div>
            {
            [places.slice(0, maxShown).map((place) => {
                console.log(place.properties.xid);
                return <PlaceCardContainer id={place.properties.xid} />;
            })]
            }
        </div>
    );
}

export { CardsListContainer }