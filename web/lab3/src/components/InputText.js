function InputText({ onSubmit, handleChange }) {
    return (
        <form onSubmit={onSubmit}>
            <input type="text" name="input" onChange={handleChange} />
            <button type="submit">Search!</button>
        </form>

    );
}

export { InputText };
