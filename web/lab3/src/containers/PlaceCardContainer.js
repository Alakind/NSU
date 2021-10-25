import { useEffect, useState } from "react";
import { PlaceCard } from "../components";
import { fetchPlace } from "../utils/helpers";

function PlaceCardContainer({ id }) {
    const [place, setPlace] = useState(undefined);

    useEffect(() => {
        fetchPlace(id, setPlace);
    }, [id]);

    return (
        <>
            {console.log(place)}
            {
            (place === undefined)
                ?
            <div>Loading place info...</div>
                :
            <PlaceCard place={place} />
            }
        </>
    );
}

export { PlaceCardContainer };
