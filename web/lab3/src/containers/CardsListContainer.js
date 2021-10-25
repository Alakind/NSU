import { PlaceCardContainer } from "./PlaceCardContainer";

function CardsListContainer({ places, maxShown }) {
    return (
        <div>
            {
            [places.slice(0, maxShown).map((place) => {
                return <PlaceCardContainer key={place.properties.xid} id={place.properties.xid} />;
            })]
            }
        </div>
    );
}

export { CardsListContainer }